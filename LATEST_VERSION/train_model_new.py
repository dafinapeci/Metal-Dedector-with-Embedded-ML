import pandas as pd
import numpy as np
import glob
import os
import m2cgen as m2c
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.preprocessing import LabelEncoder

# ==========================================
# 1. LOAD AND PREPARE DATA
# ==========================================
print(">>> STEP 1: Loading Dataset...")

# Find all CSV files in the current folder
csv_files = glob.glob("*.csv")

if not csv_files:
    print("ERROR: No CSV files found in the directory!")
    exit()

# Combine all CSVs into one DataFrame
df_list = []
for file in csv_files:
    try:
        temp_df = pd.read_csv(file)
        # Check if it has our expected columns
        if 'Label' in temp_df.columns and '10kHz' in temp_df.columns:
            df_list.append(temp_df)
    except Exception as e:
        pass

if not df_list:
    print("ERROR: No valid data found in CSV files. Ensure header is Label,10kHz,40kHz,80kHz")
    exit()

data = pd.concat(df_list, ignore_index=True)

# Drop any rows with empty values or string headers accidentally caught in the middle
data = data.dropna()
data = data[data['10kHz'].apply(lambda x: str(x).replace('.', '', 1).isdigit())]

# Convert feature columns to floats
features = ['10kHz', '40kHz', '80kHz']
for col in features:
    data[col] = data[col].astype(float)

# Encode Labels (e.g., Aluminyum -> 0, Bakir -> 1, Celik -> 2)
le = LabelEncoder()
data['Target'] = le.fit_transform(data['Label'])
class_names = le.classes_

print(f"Data Loaded Successfully! Total Samples: {len(data)}")
print("Classes found:", class_names)
print(data['Label'].value_counts())
print("\n")

# ==========================================
# 2. TRAIN MACHINE LEARNING MODEL
# ==========================================
print(">>> STEP 2: Training Random Forest Model...")

X = data[features].values
y = data['Target'].values

# Split data into 80% training and 20% testing
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

# Initialize and train the Random Forest
# Max depth 5 and 30 estimators keeps the exported C code lightweight for the ESP32
rf_model = RandomForestClassifier(n_estimators=30, max_depth=5, random_state=42)
rf_model.fit(X_train, y_train)

# Evaluate the model
accuracy = rf_model.score(X_test, y_test)
print(f"Model Accuracy on Test Data: {accuracy * 100:.2f}%\n")

y_pred = rf_model.predict(X_test)
print("Detailed Classification Report:")
print(classification_report(y_test, y_pred, target_names=class_names))

# ==========================================
# 3. GENERATE CONFUSION MATRIX GRAPH
# ==========================================
print(">>> STEP 3: Generating Confusion Matrix...")
cm = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(6, 5))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=class_names, yticklabels=class_names)
plt.title("Metal Detection Confusion Matrix")
plt.ylabel("Actual Metal")
plt.xlabel("Predicted Metal")
plt.tight_layout()
plt.savefig("confusion_matrix.png")
print("Saved 'confusion_matrix.png' to your folder.\n")

# ==========================================
# 4. EXPORT TO ESP32 C CODE
# ==========================================
print(">>> STEP 4: Exporting Model for Arduino/ESP32...")

# Generate raw C code using m2cgen
c_code = m2c.export_to_c(rf_model)

# Create the wrapper header file for your specific ESP32 project
header_content = f"""// AUTO-GENERATED RANDOM FOREST MODEL
// Trained on: {', '.join(class_names)}
// Accuracy: {accuracy * 100:.2f}%

#ifndef RF_MODEL_H
#define RF_MODEL_H

#include <stdint.h>

{c_code}

// Wrapper function to match your ESP32 Arduino code
int rf_model_predict(int16_t* input_features, int length) {{
    // Convert int16_t array from Arduino to double array for the model
    double model_input[3];
    model_input[0] = (double)input_features[0];
    model_input[1] = (double)input_features[1];
    model_input[2] = (double)input_features[2];

    // Array to hold the probability scores for each class
    double scores[{len(class_names)}];

    // Call the m2cgen generated function
    score(model_input, scores);

    // Find the class with the highest probability
    int best_class = 0;
    double max_score = scores[0];

    for(int i = 1; i < {len(class_names)}; i++) {{
        if(scores[i] > max_score) {{
            max_score = scores[i];
            best_class = i;
        }}
    }}

    return best_class;
}}

#endif
"""

with open("rf_model.h", "w") as f:
    f.write(header_content)

print("Export Complete! 'rf_model.h' has been generated.")
print("Drop 'rf_model.h' into your Arduino Sketch folder and uncomment the ML code to run live predictions!")
