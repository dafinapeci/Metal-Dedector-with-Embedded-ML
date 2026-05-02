# ============================================================
# METAL DETECTOR — TRAINING PIPELINE
# CENG318 Project — Prepared by: Dafina Peci
# Run this file after collecting CSV files from the device
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
from sklearn.metrics import classification_report, confusion_matrix
import m2cgen as m2c
import warnings
warnings.filterwarnings('ignore')

# ─── CONFIGURATION ────────────────────────────────────────
# Map each CSV filename (without .csv) to its class label
# Add or remove files here as you collect more data
FILE_CLASS_MAP = {
    # ── Aluminium (class 1) ──────────────────────────────
    "aluminium_can_2cm":      ("Aluminium", 1),
    "aluminium_can_4cm":      ("Aluminium", 1),
    "aluminium_can_less1cm":  ("Aluminium", 1),
    "aluminium_foil_2cm":     ("Aluminium", 1),
    "aluminium_foil_4cm":     ("Aluminium", 1),
    "aluminium_foil_less1cm": ("Aluminium", 1),

    # ── Gold (class 2) ───────────────────────────────────
    "gold_ring_2cm":          ("Gold",      2),
    "gold_ring_4cm":          ("Gold",      2),
    "gold_ring_less1cm":      ("Gold",      2),
    "gold_ring2_2cm":         ("Gold",      2),
    "gold_rings2_2cm": ("Gold", 2),
    "gold_rings2_4cm": ("Gold", 2),
    "gold_rings2_less1cm": ("Gold", 2),
    "gold_rings_2cm": ("Gold", 2),
    "gold_rings_4cm": ("Gold", 2),
    "gold_rings_less1cm": ("Gold", 2),

    # ── Silver (class 3) ─────────────────────────────────
    "silver_clump_2cm":       ("Silver",    3),
    "silver_ring_0_5-1cm":    ("Silver",    3),
    "silver_ring_2cm":        ("Silver",    3),
    "silver_ring_4cm":        ("Silver",    3),

    # ── Steel (class 4) ──────────────────────────────────
    "steel_knife_less1cm":    ("Steel",     4),
    "steel_knife_2cm":    ("Steel",     4),
    "steel_knife_4cm": ("Steel", 4),
    "steel_ring_2cm": ("Steel", 4),
    "steel_ring_4cm": ("Steel", 4),
    "steel_ring_less1cm": ("Steel", 4),
    "steel_spoon_2cm": ("Steel", 4),
    "steel_spoon_4cm": ("Steel", 4),
    "steel_spoon_less1cm": ("Steel", 4),

    # ── NoMetal (class 0) ────────────────────────────────
    "empty_space": ("NoMetal",   0),
    "empty_space2": ("NoMetal",   0),
    "food": ("NoMetal", 0),
    "kolonya": ("NoMetal", 0),
    "paper": ("NoMetal", 0),
    "plastic": ("NoMetal", 0),
    "porcelain": ("NoMetal", 0),
    "wood": ("NoMetal", 0),
}
DATA_FOLDER   = "."        # folder where CSV files are
OUTPUT_FOLDER = "./output"
RANDOM_SEED   = 42
NUM_FEATURES  = 20
# ──────────────────────────────────────────────────────────

np.random.seed(RANDOM_SEED)
os.makedirs(OUTPUT_FOLDER, exist_ok=True)

RAW_COLS  = [f"raw_t{i}"  for i in range(NUM_FEATURES)]
FARK_COLS = [f"fark_t{i}" for i in range(NUM_FEATURES)]
ALL_COLS  = RAW_COLS + FARK_COLS

CLASS_NAMES = {}  # will be filled from FILE_CLASS_MAP

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

    if df.shape[1] != 40:
        print(f"  ERROR: {fname}.csv has {df.shape[1]} columns, need 40. Skipping.")
        continue

    df.columns = ALL_COLS
    df["label"] = class_idx
    df["class_name"] = class_name
    CLASS_NAMES[class_idx] = class_name

    for col in ALL_COLS:
        df[col] = pd.to_numeric(df[col], errors='coerce')
    df = df.dropna()

    print(f"  {fname}: {len(df)} rows → class {class_idx} ({class_name})")
    all_dfs.append(df)

data = pd.concat(all_dfs, ignore_index=True)
sorted_classes = sorted(CLASS_NAMES.keys())
class_name_list = [CLASS_NAMES[i] for i in sorted_classes]

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

X = data[ALL_COLS].values.astype(np.float32)
y = data["label"].values.astype(int)

# ESP32 12-bit ADC: raw values must be 0-4095
# Delta values must be 0-4095
valid_range = np.all((X >= 0) & (X <= 4095), axis=1)

# Signal must not be completely flat
raw_only = X[:, :20]
not_flat  = (np.max(raw_only, axis=1) - np.min(raw_only, axis=1)) > 5

mask = valid_range & not_flat
print(f"  Removed {np.sum(~mask)} bad rows")
print(f"  Kept {np.sum(mask)} valid rows")

X = X[mask]
y = y[mask]

# ============================================================
# STEP 3: CROSS-VALIDATION (reliable accuracy estimate)
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
    "Random Forest (30)": RandomForestClassifier(n_estimators=30,
                               max_depth=8, random_state=RANDOM_SEED),
}

cv_results = {}
print(f"\n  {'Model':<22} {'Mean Acc':>10} {'Std':>8}")
print(f"  {'─'*42}")
for name, model in models.items():
    scores = cross_val_score(model, X, y, cv=cv, scoring='accuracy')
    cv_results[name] = scores
    print(f"  {name:<22} {scores.mean()*100:>9.1f}% {scores.std()*100:>7.1f}%")

# ============================================================
# STEP 4: TRAIN FINAL MODELS ON FULL TRAIN SET
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

knn_final = KNeighborsClassifier(n_neighbors=5)
svm_final = SVC(kernel='rbf', C=10, gamma='scale', random_state=RANDOM_SEED)
rf_final  = RandomForestClassifier(n_estimators=30, max_depth=8,
                                    random_state=RANDOM_SEED, n_jobs=-1)

knn_final.fit(X_train, y_train)
svm_final.fit(X_train, y_train)
rf_final.fit(X_train, y_train)

knn_acc = knn_final.score(X_test, y_test)
svm_acc = svm_final.score(X_test, y_test)
rf_acc  = rf_final.score(X_test,  y_test)

print(f"\n  Test set results:")
print(f"  k-NN:           {knn_acc*100:.1f}%")
print(f"  SVM:            {svm_acc*100:.1f}%")
print(f"  Random Forest:  {rf_acc*100:.1f}%")

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

# Figure A — Sample waveforms per class
fig, axes = plt.subplots(1, len(sorted_classes),
                          figsize=(5*len(sorted_classes), 3.5))
if len(sorted_classes) == 1:
    axes = [axes]
colors = ['#95a5a6','#e74c3c','#3498db','#2ecc71','#e67e22']
fig.suptitle("Sample ADC Decay Curves per Metal Class",
             fontweight='bold', fontsize=13)
for i, idx in enumerate(sorted_classes):
    mask_c = y == idx
    if np.sum(mask_c) == 0:
        continue
    sample = X[mask_c][0][:20]  # first 20 = raw values
    axes[i].plot(sample, color=colors[i % len(colors)], linewidth=2)
    axes[i].set_title(CLASS_NAMES[idx], fontweight='bold')
    axes[i].set_xlabel("Time point (0–19)")
    if i == 0:
        axes[i].set_ylabel("ADC counts")
    axes[i].grid(True, alpha=0.3)
    axes[i].set_ylim(580, 690)
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
plt.bar(range(top_n),
        importances[top_idx],
        color='#2980b9', edgecolor='white')
plt.xticks(range(top_n),
           [ALL_COLS[i] for i in top_idx],
           rotation=40, ha='right', fontsize=9)
plt.title(f"Top {top_n} Feature Importances — Random Forest (Gini)",
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

# Figure D — Delta value distribution per class (shows separability)
fig, ax = plt.subplots(figsize=(9, 4))
delta_means_by_class = {}
for idx in sorted_classes:
    mask_c = y == idx
    delta_vals = X[mask_c][:, 20:]  # columns 20-39 are deltas
    mean_per_sample = delta_vals.mean(axis=1)
    delta_means_by_class[CLASS_NAMES[idx]] = mean_per_sample
    ax.scatter(np.where(mask_c)[0],
               mean_per_sample,
               label=CLASS_NAMES[idx],
               color=colors[idx % len(colors)],
               alpha=0.6, s=20)
ax.set_xlabel("Sample index")
ax.set_ylabel("Mean delta value (baseline - reading)")
ax.set_title("Class Separability — Mean Delta Value per Sample",
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

header = f"""// =====================================================
// AUTO-GENERATED BY train_model.py — DO NOT EDIT
// Model: Random Forest ({len(rf_final.estimators_)} trees, max_depth={rf_final.max_depth})
// Input:  float features[40]  (20 raw + 20 delta)
// Output: int classIndex (0={class_name_list[0]},
//         1={class_name_list[1] if len(class_name_list)>1 else '?'},
//         2={class_name_list[2] if len(class_name_list)>2 else '?'})
// Training accuracy: {rf_acc*100:.1f}%
// CV accuracy:       {cv_results['Random Forest (30)'].mean()*100:.1f}%
// =====================================================

#ifndef METAL_MODEL_H
#define METAL_MODEL_H

#define NUM_CLASSES  {len(sorted_classes)}
#define NUM_FEATURES 40

// Class label strings — index matches model output
const char* CLASS_LABELS[NUM_CLASSES] = {{
  {', '.join([f'"{CLASS_NAMES[i]}"' for i in sorted_classes])}
}};

// Minimum vote fraction to accept a prediction
// Below this → display "Unknown"
#define CONFIDENCE_THRESHOLD 0.50f

// ── m2cgen generated model (pure C, no libraries) ──
{c_code}

// ── Easy-to-use wrapper ──
// Call this with your 40-feature array
// Returns class index, sets *confidence to vote fraction
int predictMetal(float* features, float* confidence) {{
  // Convert float input to double for m2cgen score() function
  double input[40];
  for (int i = 0; i < 40; i++) {{
    input[i] = (double)features[i];
  }}

  double scores[5];
  score(input, scores);

  int best = 0;
  double bestScore = scores[0];
  for (int i = 1; i < 5; i++) {{
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
    "num_features": 40,
    "feature_description": "20 raw ADC values + 20 delta values",
    "cross_validation_5fold": {
        name: {
            "mean": f"{s.mean()*100:.1f}%",
            "std":  f"{s.std()*100:.1f}%"
        } for name, s in cv_results.items()
    },
    "test_set_accuracy": {
        "kNN_k5":      f"{knn_acc*100:.1f}%",
        "SVM_RBF":     f"{svm_acc*100:.1f}%",
        "RandomForest": f"{rf_acc*100:.1f}%"
    },
    "selected_model": "Random Forest (30 trees, max_depth=8)",
    "selection_reason": "Highest accuracy, exportable to C via m2cgen, no external library on ESP32"
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