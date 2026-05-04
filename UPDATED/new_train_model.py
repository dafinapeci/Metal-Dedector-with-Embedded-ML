# ============================================================
# METAL DETECTOR — TRAINING PIPELINE
# Fixed for 80-Column CSVs (40 raw + 40 fark) | 105 Features
# ============================================================

import pandas as pd
import numpy as np
import os
import json
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split, cross_val_score, StratifiedKFold
from sklearn.ensemble import RandomForestClassifier, HistGradientBoostingClassifier
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.neural_network import MLPClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline
from sklearn.metrics import classification_report, confusion_matrix

try:
    from xgboost import XGBClassifier
    HAS_XGBOOST = True
except ImportError:
    HAS_XGBOOST = False
    print("  NOTE: xgboost not installed — XGBoost model skipped.")

try:
    import m2cgen as m2c
    HAS_M2CGEN = True
except ImportError:
    HAS_M2CGEN = False
    print("  NOTE: m2cgen not installed — C code export will be skipped.")
    print("        Install with: pip install m2cgen")

import warnings
warnings.filterwarnings('ignore')

# ─── CONFIGURATION ────────────────────────────────────────
FILE_CLASS_MAP = {
    "aluminyum_b2": ("Aluminium",  0),
    "bakira":       ("Copper",     1),
}

DATA_FOLDER   = "."
OUTPUT_FOLDER = "./output"
RANDOM_SEED   = 42

# FIX: Update CSV_COLS to 80 (40 raw + 40 fark)
CSV_COLS      = 80
NUM_ENGINEERED_FEATURES = 105   # Updated to reflect 40-step arrays
# ──────────────────────────────────────────────────────────

np.random.seed(RANDOM_SEED)
os.makedirs(OUTPUT_FOLDER, exist_ok=True)

# Update layout: 40 raw ADC readings + 40 delta (fark)
RAW_COLS  = [f"raw_t{i}"  for i in range(40)]
FARK_COLS = [f"fark_t{i}" for i in range(40)]
ALL_CSV_COLS = RAW_COLS + FARK_COLS

CLASS_NAMES = {}

# ============================================================
# STEP 1: LOAD DATA
# ============================================================
print("=" * 60)
print("STEP 1: Loading CSV files")
print("=" * 60)

all_dfs = []
for fname, (class_name, class_idx) in FILE_CLASS_MAP.items():
    filepath = os.path.join(DATA_FOLDER, f"{fname}.csv")
    if not os.path.exists(filepath):
        print(f"  WARNING: {filepath} not found, skipping.")
        continue

    df = pd.read_csv(filepath, header=None)

    if df.shape[1] != CSV_COLS:
        print(f"  ERROR: {fname}.csv has {df.shape[1]} columns, need {CSV_COLS}. Skipping.")
        continue

    df.columns = ALL_CSV_COLS
    df["label"]      = class_idx
    df["class_name"] = class_name
    CLASS_NAMES[class_idx] = class_name

    for col in ALL_CSV_COLS:
        df[col] = pd.to_numeric(df[col], errors='coerce')
    df = df.dropna()

    print(f"  {fname}: {len(df)} rows → class {class_idx} ({class_name})")
    all_dfs.append(df)

if not all_dfs:
    print("\nCRITICAL ERROR: No valid CSV files were loaded!")
    exit()

data = pd.concat(all_dfs, ignore_index=True)
sorted_classes  = sorted(CLASS_NAMES.keys())
class_name_list = [CLASS_NAMES[i] for i in sorted_classes]
num_classes     = len(sorted_classes)

print(f"\n  Total: {len(data)} samples")
for idx in sorted_classes:
    count = len(data[data['label'] == idx])
    print(f"  Class {idx} ({CLASS_NAMES[idx]}): {count} samples")

# ============================================================
# STEP 2: QUALITY CONTROL
# ============================================================
print()
print("=" * 60)
print("STEP 2: Quality Control")
print("=" * 60)

raw_data  = data[RAW_COLS].values.astype(np.float32)
fark_data = data[FARK_COLS].values.astype(np.float32)
y         = data["label"].values.astype(int)

# Broadened the acceptable raw limits slightly in case of sensor drift
valid_raw  = np.all((raw_data  >= 200) & (raw_data  <= 2000), axis=1)
valid_fark = np.all((fark_data >= 0)   & (fark_data <= 4095), axis=1)
not_flat   = (np.max(fark_data, axis=1) - np.min(fark_data, axis=1)) > 0.5

mask = valid_raw & valid_fark & not_flat
print(f"  Removed {np.sum(~mask)} bad rows")
print(f"  Kept    {np.sum(mask)} valid rows")

raw_data  = raw_data[mask]
fark_data = fark_data[mask]
y         = y[mask]

# ============================================================
# STEP 2B: FEATURE ENGINEERING (105 Features)
# ============================================================
print()
print("=" * 60)
print("STEP 2B: Feature Engineering (105 features total)")
print("=" * 60)

feat_fark = fark_data

# Scaled quadrants to 40 columns (10 steps each)
q1_energy = np.sum(np.abs(fark_data[:, 0:10]),   axis=1, keepdims=True)
q2_energy = np.sum(np.abs(fark_data[:, 10:20]),  axis=1, keepdims=True)
q3_energy = np.sum(np.abs(fark_data[:, 20:30]), axis=1, keepdims=True)
q4_energy = np.sum(np.abs(fark_data[:, 30:40]), axis=1, keepdims=True)
total_energy = q1_energy + q2_energy + q3_energy + q4_energy

feat_variance = np.var(fark_data, axis=1, keepdims=True)

# Scaled macro slopes to fit the 40 step range
entry_slope = (np.mean(fark_data[:, 6:12], axis=1, keepdims=True)
             - np.mean(fark_data[:, 0:6],   axis=1, keepdims=True))
exit_slope  = (np.mean(fark_data[:, 34:40], axis=1, keepdims=True)
             - np.mean(fark_data[:, 28:34], axis=1, keepdims=True))

peak_val = np.max(fark_data,    axis=1, keepdims=True)
peak_pos = np.argmax(fark_data, axis=1, keepdims=True).astype(np.float32)

raw_mean = np.mean(raw_data, axis=1, keepdims=True)
raw_std  = np.std(raw_data,  axis=1, keepdims=True)
raw_min  = np.min(raw_data,  axis=1, keepdims=True)
raw_max  = np.max(raw_data,  axis=1, keepdims=True)
raw_var  = np.var(raw_data,  axis=1, keepdims=True)

front_back_ratio = (q1_energy + q2_energy + 1e-6) / (q3_energy + q4_energy + 1e-6)
q_symmetry       = np.abs(q1_energy - q4_energy) / (q1_energy + q4_energy + 1e-6)
peak_norm        = peak_val / (raw_mean + 1e-6)
fark_to_raw      = total_energy / (raw_mean + 1e-6)
fark_mean        = np.mean(fark_data, axis=1, keepdims=True)
fark_std         = np.std(fark_data,  axis=1, keepdims=True)

fark_med  = np.median(fark_data, axis=1, keepdims=True)
fark_skew = (fark_mean - fark_med) / (fark_std + 1e-6)
fark_iqr  = (np.percentile(fark_data, 75, axis=1, keepdims=True)
           - np.percentile(fark_data, 25, axis=1, keepdims=True))
raw_range = raw_max - raw_min

# Scaled time weights for 40 columns
time_weights   = np.arange(40, dtype=np.float32).reshape(1, 40)
weighted_peak_time = np.sum(fark_data * time_weights, axis=1, keepdims=True) / (total_energy + 1e-6)

feat_raw = raw_data

# Stack all features
X = np.hstack([
    feat_fark,            # 40  [0..39]
    q1_energy,            #  1  [40]
    q2_energy,            #  1  [41]
    q3_energy,            #  1  [42]
    q4_energy,            #  1  [43]
    feat_variance,        #  1  [44]
    entry_slope,          #  1  [45]
    exit_slope,           #  1  [46]
    peak_val,             #  1  [47]
    peak_pos,             #  1  [48]
    total_energy,         #  1  [49]
    raw_mean,             #  1  [50]
    raw_std,              #  1  [51]
    raw_min,              #  1  [52]
    raw_max,              #  1  [53]
    raw_var,              #  1  [54]
    front_back_ratio,     #  1  [55]
    q_symmetry,           #  1  [56]
    peak_norm,            #  1  [57]
    fark_to_raw,          #  1  [58]
    fark_mean,            #  1  [59]
    fark_std,             #  1  [60]
    fark_skew,            #  1  [61]
    fark_iqr,             #  1  [62]
    raw_range,            #  1  [63]
    weighted_peak_time,   #  1  [64]
    feat_raw,             # 40  [65..104]
])

assert X.shape[1] == NUM_ENGINEERED_FEATURES

feat_names = (
    [f"fark_t{i}" for i in range(40)] +
    ["q1_energy","q2_energy","q3_energy","q4_energy","variance",
     "entry_slope","exit_slope","peak_val","peak_pos","total_energy",
     "raw_mean","raw_std","raw_min","raw_max","raw_var",
     "front_back_ratio","q_symmetry","peak_norm","fark_to_raw",
     "fark_mean","fark_std","fark_skew","fark_iqr","raw_range","weighted_peak_time"] +
    [f"raw_t{i}" for i in range(40)]
)

# ============================================================
# STEP 3: CROSS-VALIDATION
# ============================================================
print()
print("=" * 60)
print("STEP 3: Cross-Validation (5-fold, stratified)")
print("=" * 60)

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=RANDOM_SEED)

# Tuned Random Forest to try and cross the 75% threshold
models = {
    "SVM (RBF, Tuned)":     Pipeline([("sc", StandardScaler()),
                                       ("clf", SVC(kernel='rbf', C=10, gamma='scale', random_state=RANDOM_SEED))]),
    "Random Forest (Opt)":  RandomForestClassifier(n_estimators=300, max_depth=12,
                                                    min_samples_split=2, min_samples_leaf=1,
                                                    random_state=RANDOM_SEED, n_jobs=-1),
    "HistGradBoost":        HistGradientBoostingClassifier(max_iter=300, max_depth=8,
                                                           learning_rate=0.05,
                                                           random_state=RANDOM_SEED)
}

cv_results = {}
for name, model in models.items():
    scores = cross_val_score(model, X, y, cv=cv, scoring='accuracy')
    cv_results[name] = scores
    print(f"  {name:<26} {scores.mean()*100:>9.2f}% {scores.std()*100:>7.2f}%")

# ============================================================
# STEP 4: TRAIN FINAL MODELS
# ============================================================
print()
print("=" * 60)
print("STEP 4: Training Final Models")
print("=" * 60)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.20, random_state=RANDOM_SEED, stratify=y
)

trained = {}
for name, model in models.items():
    model.fit(X_train, y_train)
    acc = model.score(X_test, y_test)
    trained[name] = (model, acc)

print(f"\n  Test set results:")
for name, (model, acc) in trained.items():
    print(f"  {name:<26}  {acc*100:.2f}%")

rf_name  = "Random Forest (Opt)"
rf_final = trained[rf_name][0]
rf_acc   = trained[rf_name][1]

y_pred = rf_final.predict(X_test)
print(f"\n  Random Forest — Per-class Report:")
print(classification_report(y_test, y_pred, target_names=class_name_list))

# ============================================================
# STEP 5 & 6: EXPORT MODEL TO C CODE
# ============================================================
print()
print("=" * 60)
print("STEP 6: Exporting Random Forest to C code")
print("=" * 60)

if not HAS_M2CGEN:
    print("  SKIPPED — m2cgen not installed.")
else:
    c_code = m2c.export_to_c(rf_final)
    header = f"""// AUTO-GENERATED BY train_model.py
// Model: Random Forest ({len(rf_final.estimators_)} trees)
// Input:  float features[{NUM_ENGINEERED_FEATURES}]
#ifndef METAL_MODEL_H
#define METAL_MODEL_H

#define NUM_CLASSES  {num_classes}
#define NUM_FEATURES {NUM_ENGINEERED_FEATURES}

{c_code}

int predictMetal(float* features, float* confidence) {{
  double input[{NUM_ENGINEERED_FEATURES}];
  for (int i = 0; i < {NUM_ENGINEERED_FEATURES}; i++) {{ input[i] = (double)features[i]; }}
  double scores[NUM_CLASSES];
  score(input, scores);
  int best = 0;
  double bestScore = scores[0];
  for (int i = 1; i < NUM_CLASSES; i++) {{
    if (scores[i] > bestScore) {{ bestScore = scores[i]; best = i; }}
  }}
  if (confidence != NULL) *confidence = (float)bestScore;
  return best;
}}
#endif
"""
    out_path = os.path.join(OUTPUT_FOLDER, "metal_model.h")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write(header)
    print(f"  metal_model.h saved successfully.")
