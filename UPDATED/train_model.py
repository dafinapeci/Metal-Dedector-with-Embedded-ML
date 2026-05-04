# ============================================================
# METAL DETECTOR — TRAINING PIPELINE
# CENG318 Project — Prepared by: Dafina Peci
# Modified for 20-Column CSVs and 27 Key Features
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
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.neural_network import MLPClassifier
from xgboost import XGBClassifier # (You may need to run: pip install xgboost)
from sklearn.metrics import classification_report, confusion_matrix
import m2cgen as m2c
import warnings
warnings.filterwarnings('ignore')

# ─── CONFIGURATION ────────────────────────────────────────
FILE_CLASS_MAP = {
    # ── Aluminium (class 1) ──────────────────────────────
    "aluminium":           ("Aluminium", 0),
    "aluminium2":           ("Aluminium", 0),

    # ── Steel (class 2) ──────────────────────────────────
    "steel":               ("Steel",     1),
    "steel1":               ("Steel",     1),



    # ── NoMetal (class 0) ────────────────────────────────
    # Assuming you still have empty files. If not, add an "empty" file!

}

DATA_FOLDER   = "."
OUTPUT_FOLDER = "./output"
RANDOM_SEED   = 42
CSV_COLS      = 20

NUM_ENGINEERED_FEATURES = 27  # 20 + 4 + 1 + 2
# ──────────────────────────────────────────────────────────

np.random.seed(RANDOM_SEED)
os.makedirs(OUTPUT_FOLDER, exist_ok=True)

# WE NOW ONLY EXPECT 20 COLUMNS (The Fark/Delta values)
FARK_COLS    = [f"fark_t{i}" for i in range(CSV_COLS)]
ALL_CSV_COLS = FARK_COLS

CLASS_NAMES = {}

# ============================================================
# STEP 1: LOAD DATA
# ============================================================
print("=" * 55)
print("STEP 1: Loading CSV files")
print("=" * 55)

all_dfs = []
for fname, (class_name, class_idx) in FILE_CLASS_MAP.items():
    filepath = os.path.join(DATA_FOLDER, f"{fname}.csv")
    if not os.path.exists(filepath):
        print(f"  WARNING: {filepath} not found, skipping.")
        continue

    df = pd.read_csv(filepath, header=None)

    # CHANGED: Now checks for 20 columns instead of 40
    if df.shape[1] != 20:
        print(f"  ERROR: {fname}.csv has {df.shape[1]} columns, need 20. Skipping.")
        continue

    df.columns = ALL_CSV_COLS
    df["label"] = class_idx
    df["class_name"] = class_name
    CLASS_NAMES[class_idx] = class_name

    for col in ALL_CSV_COLS:
        df[col] = pd.to_numeric(df[col], errors='coerce')
    df = df.dropna()

    print(f"  {fname}: {len(df)} rows → class {class_idx} ({class_name})")
    all_dfs.append(df)

if len(all_dfs) == 0:
    print("\nCRITICAL ERROR: No valid CSV files were loaded. Check your folder and file names!")
    exit()

data = pd.concat(all_dfs, ignore_index=True)
sorted_classes = sorted(CLASS_NAMES.keys())
class_name_list = [CLASS_NAMES[i] for i in sorted_classes]
num_classes = len(sorted_classes)

print(f"\n  Total: {len(data)} samples")
for idx in sorted_classes:
    count = len(data[data['label'] == idx])
    print(f"  Class {idx} ({CLASS_NAMES[idx]}): {count} samples")

# ============================================================
# STEP 2: QUALITY CONTROL
# ============================================================
print()
print("=" * 55)
print("STEP 2: Quality Control")
print("=" * 55)

fark_raw = data[FARK_COLS].values.astype(np.float32)
y = data["label"].values.astype(int)

# Delta values must be 0-4095
valid_range = np.all((fark_raw >= 0) & (fark_raw <= 4095), axis=1)

# Lenient flat check
not_flat = (np.max(fark_raw, axis=1) - np.min(fark_raw, axis=1)) > 0.5

mask = valid_range & not_flat
print(f"  Removed {np.sum(~mask)} bad rows")
print(f"  Kept    {np.sum(mask)} valid rows")

fark_raw = fark_raw[mask]
y        = y[mask]

# ============================================================
# STEP 2B: FEATURE ENGINEERING (27 Features)
# ============================================================
print()
print("=" * 55)
print("STEP 2B: Feature Engineering (27 features total)")
print("=" * 55)

# 1. Ham Farklar (Delta) - [20 Özellik]
feat_delta = fark_raw

# 2. Bölgesel Enerjiler (Eğri Altında Kalan Alan) - [4 Özellik]
q1_energy = np.sum(np.abs(fark_raw[:, 0:5]), axis=1, keepdims=True)
q2_energy = np.sum(np.abs(fark_raw[:, 5:10]), axis=1, keepdims=True)
q3_energy = np.sum(np.abs(fark_raw[:, 10:15]), axis=1, keepdims=True)
q4_energy = np.sum(np.abs(fark_raw[:, 15:20]), axis=1, keepdims=True)
feat_quarters = np.hstack([q1_energy, q2_energy, q3_energy, q4_energy])

# 3. Sinyal Varyansı (Pürüzlülük/Dalgalanma) - [1 Özellik]
feat_variance = np.var(fark_raw, axis=1, keepdims=True)

# 4. Kısmi Eğimler (Saldırı ve Sönümleme Hızı) - [2 Özellik]
entry_slope = np.mean(fark_raw[:, 3:6], axis=1, keepdims=True) - np.mean(fark_raw[:, 0:3], axis=1, keepdims=True)
exit_slope  = np.mean(fark_raw[:, 17:20], axis=1, keepdims=True) - np.mean(fark_raw[:, 14:17], axis=1, keepdims=True)
feat_macro_slopes = np.hstack([entry_slope, exit_slope])

# Combine exactly 27 features
X = np.hstack([feat_delta, feat_quarters, feat_variance, feat_macro_slopes])

print(f"  Feature breakdown:")
print(f"    Ham Farklar (fark_t0..19):      20")
print(f"    Bölgesel Enerjiler (Q1..Q4):     4")
print(f"    Sinyal Varyansı:                 1")
print(f"    Kısmi Eğimler (Giriş, Çıkış):    2")
print(f"    ─────────────────────────────────")
print(f"    Total:                          {X.shape[1]}")

feat_names = (
    [f"fark_t{i}" for i in range(20)] +
    ["q1_energy", "q2_energy", "q3_energy", "q4_energy", "variance", "entry_slope", "exit_slope"]
)

# ============================================================
# STEP 3: CROSS-VALIDATION
# ============================================================
print()
print("=" * 55)
print("STEP 3: Cross-Validation (5-fold, stratified)")
print("=" * 55)

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=RANDOM_SEED)

models = {
    "k-NN (k=5)":         KNeighborsClassifier(n_neighbors=5),
    "SVM (RBF, C=10)":    SVC(kernel='rbf', C=10, gamma='scale',
                               random_state=RANDOM_SEED),
    "Random Forest (15)": RandomForestClassifier(n_estimators=15, max_depth=6, random_state=RANDOM_SEED, n_jobs=-1),
    "Logistic Regression": LogisticRegression(max_iter=1000, random_state=RANDOM_SEED),
    "Neural Net (MLP)": MLPClassifier(hidden_layer_sizes=(15,), max_iter=500, random_state=RANDOM_SEED),
    "XGBoost": XGBClassifier(n_estimators=10, max_depth=4, learning_rate=0.1, random_state=RANDOM_SEED),
}

cv_results = {}
print(f"\n  {'Model':<22} {'Mean Acc':>10} {'Std':>8}")
print(f"  {'─'*42}")
for name, model in models.items():
    scores = cross_val_score(model, X, y, cv=cv, scoring='accuracy')
    cv_results[name] = scores
    print(f"  {name:<22} {scores.mean()*100:>9.1f}% {scores.std()*100:>7.1f}%")

# ============================================================
# STEP 4: TRAIN FINAL MODELS
# ============================================================
print()
print("=" * 55)
print("STEP 4: Training Final Models")
print("=" * 55)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.20,
    random_state=RANDOM_SEED, stratify=y
)
print(f"  Train: {len(X_train)}  Test: {len(X_test)}")

# --- 1. INSTANTIATE THE MODELS ---
knn_final     = KNeighborsClassifier(n_neighbors=5)
svm_final     = SVC(kernel='rbf', C=10, gamma='scale', random_state=RANDOM_SEED)
rf_final      = RandomForestClassifier(n_estimators=15, max_depth=6, random_state=RANDOM_SEED, n_jobs=-1)
log_reg       = LogisticRegression(max_iter=1000, random_state=RANDOM_SEED)
mlp_final     = MLPClassifier(hidden_layer_sizes=(15,), max_iter=500, random_state=RANDOM_SEED)
xgboost_final = XGBClassifier(n_estimators=10, max_depth=4, learning_rate=0.1, random_state=RANDOM_SEED)

# --- 2. FIT THE MODELS ---
knn_final.fit(X_train, y_train)
svm_final.fit(X_train, y_train)
rf_final.fit(X_train, y_train)
log_reg.fit(X_train, y_train)
mlp_final.fit(X_train, y_train)
xgboost_final.fit(X_train, y_train)

# --- 3. SCORE THE MODELS ---
knn_acc     = knn_final.score(X_test, y_test)
svm_acc     = svm_final.score(X_test, y_test)
rf_acc      = rf_final.score(X_test,  y_test)
log_reg_acc = log_reg.score(X_test, y_test)
mlp_acc     = mlp_final.score(X_test, y_test)
xgb_acc     = xgboost_final.score(X_test, y_test)

# --- 4. PRINT RESULTS ---
print(f"\n  Test set results:")
print(f"  k-NN:                 {knn_acc*100:.1f}%")
print(f"  SVM:                  {svm_acc*100:.1f}%")
print(f"  Random Forest:        {rf_acc*100:.1f}%")
print(f"  Logistic Regression:  {log_reg_acc*100:.1f}%")
print(f"  Neural Net (MLP):     {mlp_acc*100:.1f}%")
print(f"  XGBoost:              {xgb_acc*100:.1f}%")

y_pred = rf_final.predict(X_test)
print("\n  Random Forest — Per-class Report:")
print(classification_report(y_test, y_pred, target_names=class_name_list))

# ============================================================
# STEP 5: GENERATE REPORT FIGURES
# ============================================================
print()
print("=" * 55)
print("STEP 5: Generating Report Figures")
print("=" * 55)

colors = ['#95a5a6','#e74c3c','#3498db','#2ecc71','#e67e22']

# Figure A — Delta decay curves per class
fig, axes = plt.subplots(1, len(sorted_classes),
                          figsize=(5*len(sorted_classes), 3.5))
if len(sorted_classes) == 1:
    axes = [axes]
fig.suptitle("Sample Delta Decay Curves per Metal Class",
             fontweight='bold', fontsize=13)
for i, idx in enumerate(sorted_classes):
    mask_c = y == idx
    if np.sum(mask_c) == 0:
        continue
    sample = X[mask_c][0][:20]
    axes[i].plot(sample, color=colors[i % len(colors)], linewidth=2)
    axes[i].set_title(CLASS_NAMES[idx], fontweight='bold')
    axes[i].set_xlabel("Time point (0–19)")
    if i == 0:
        axes[i].set_ylabel("Delta (baseline - reading)")
    axes[i].grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_FOLDER, "waveforms_per_class.png"),
            dpi=150, bbox_inches='tight')
plt.close()
print("  waveforms_per_class.png → Figure 12 in report")

# Figure B — Feature importance
importances = rf_final.feature_importances_
top_n = 15
top_idx = np.argsort(importances)[::-1][:top_n]
plt.figure(figsize=(12, 5))
plt.bar(range(top_n), importances[top_idx],
        color='#2980b9', edgecolor='white')
plt.xticks(range(top_n),
           [feat_names[i] for i in top_idx],
           rotation=40, ha='right', fontsize=9)
plt.title(f"Top {top_n} Feature Importances (27 Features)",
          fontweight='bold')
plt.ylabel("Importance Score")
plt.grid(True, axis='y', alpha=0.3)
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_FOLDER, "feature_importance.png"),
            dpi=150, bbox_inches='tight')
plt.close()
print("  feature_importance.png → Figure 14 in report")

# Figure C — Confusion matrix
cm = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(6, 5))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues',
            xticklabels=class_name_list,
            yticklabels=class_name_list)
plt.title("Confusion Matrix — Test Set (Random Forest)",
          fontweight='bold')
plt.ylabel("True Label")
plt.xlabel("Predicted Label")
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_FOLDER, "confusion_matrix.png"),
            dpi=150, bbox_inches='tight')
plt.close()
print("  confusion_matrix.png → Figure 15 in report")

# Figure D — Class separability by Variance (Updated)
fig, ax = plt.subplots(figsize=(9, 4))
for idx in sorted_classes:
    mask_c = y == idx
    # index 24 is "variance" in our new 27-feature array
    variance_vals = X[mask_c][:, 24]
    ax.scatter(np.where(mask_c)[0], variance_vals,
               label=CLASS_NAMES[idx],
               color=colors[idx % len(colors)],
               alpha=0.6, s=20)
ax.set_xlabel("Sample index")
ax.set_ylabel("Signal Variance")
ax.set_title("Class Separability — Signal Variance per Sample",
             fontweight='bold')
ax.legend()
ax.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_FOLDER, "class_separability.png"),
            dpi=150, bbox_inches='tight')
plt.close()
print("  class_separability.png → Figure 13 in report")

# ============================================================
# STEP 6: EXPORT MODEL TO C CODE FOR ESP32
# ============================================================
print()
print("=" * 55)
print("STEP 6: Exporting Random Forest to C code")
print("=" * 55)

c_code = m2c.export_to_c(rf_final)
n = num_classes

header = f"""// =====================================================
// AUTO-GENERATED BY train_model.py — DO NOT EDIT
// Model: Random Forest ({len(rf_final.estimators_)} trees, max_depth={rf_final.max_depth})
// Input:  float features[{NUM_ENGINEERED_FEATURES}]
//   [0..19]  fark_t0..19        (raw delta values)
//   [20..23] q1..q4 energies    (regional energies)
//   [24]     variance           (signal variance)
//   [25]     entry_slope        (macro entry slope)
//   [26]     exit_slope         (macro exit slope)
// Output: {', '.join([f"{i}={CLASS_NAMES[i]}" for i in sorted_classes])}
// Training accuracy: {rf_acc*100:.1f}%
// CV accuracy:       {cv_results['Random Forest (15)'].mean()*100:.1f}%
// =====================================================

#ifndef METAL_MODEL_H
#define METAL_MODEL_H

#define NUM_CLASSES  {n}
#define NUM_FEATURES {NUM_ENGINEERED_FEATURES}

const char* CLASS_LABELS[NUM_CLASSES] = {{
  {', '.join([f'"{CLASS_NAMES[i]}"' for i in sorted_classes])}
}};

#define CONFIDENCE_THRESHOLD 0.50f

{c_code}

int predictMetal(float* features, float* confidence) {{
  double input[{NUM_ENGINEERED_FEATURES}];
  for (int i = 0; i < {NUM_ENGINEERED_FEATURES}; i++) {{
    input[i] = (double)features[i];
  }}

  double scores[NUM_CLASSES];
  score(input, scores);

  int best = 0;
  double bestScore = scores[0];
  for (int i = 1; i < NUM_CLASSES; i++) {{
    if (scores[i] > bestScore) {{
      bestScore = scores[i];
      best = i;
    }}
  }}
  if (confidence != NULL) *confidence = (float)bestScore;
  return best;
}}

#endif // METAL_MODEL_H
"""

out_path = os.path.join(OUTPUT_FOLDER, "metal_model.h")
with open(out_path, "w", encoding="utf-8") as f:
    f.write(header)

size_kb = os.path.getsize(out_path) / 1024
print(f"  metal_model.h saved ({size_kb:.1f} KB)")
print("  Copy this file into your Arduino sketch folder")

# ============================================================
# STEP 7: SAVE REPORT STATS
# ============================================================
stats = {
    "total_samples": int(len(X)),
    "samples_per_class": {CLASS_NAMES[i]: int(np.sum(y==i)) for i in sorted_classes},
    "train_size": int(len(X_train)),
    "test_size":  int(len(X_test)),
    "num_features": NUM_ENGINEERED_FEATURES,
    "feature_description": (
        "20 fark (delta) + 4 quarters + 1 variance + 2 macro slopes"
    ),
    "cross_validation_5fold": {
        name: {
            "mean": f"{s.mean()*100:.1f}%",
            "std":  f"{s.std()*100:.1f}%"
        } for name, s in cv_results.items()
    },
    "test_set_accuracy": {
        "kNN_k5":       f"{knn_acc*100:.1f}%",
        "SVM_RBF":      f"{svm_acc*100:.1f}%",
        "RandomForest": f"{rf_acc*100:.1f}%",
        "LogisticReg":  f"{log_reg_acc*100:.1f}%",
        "MLP":          f"{mlp_acc*100:.1f}%",
        "XGBoost":      f"{xgb_acc*100:.1f}%"
    },
    "selected_model": "Random Forest (15 trees, max_depth=6)",
    "selection_reason": "Testing all alternatives to find the best fit for ESP32 memory constraints."
}
with open(os.path.join(OUTPUT_FOLDER, "report_stats.json"), "w") as f:
    json.dump(stats, f, indent=2)

print()
print("=" * 55)
print("COMPLETE — output/ folder contains:")
print("=" * 55)
print("  metal_model.h            ← copy to Arduino sketch folder")
print("  waveforms_per_class.png  ← Figure 12 in report")
print("  class_separability.png   ← Figure 13 in report")
print("  feature_importance.png   ← Figure 14 in report")
print("  confusion_matrix.png     ← Figure 15 in report")
print("  report_stats.json        ← all numbers for report tables")