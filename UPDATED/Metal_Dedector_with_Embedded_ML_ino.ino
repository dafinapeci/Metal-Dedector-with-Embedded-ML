#include <WiFi.h>
#include "metal_model.h"

// --- PİN TANIMLAMALARI ---
const int pulsePin = 32; 
const int readPin = 33;  
const int buttonPin = 0; 

// --- TEK LED (SADECE METAL TESPİTİ İÇİN) ---
const int alarmPin = 25; 


// --- ML ÖZNİTELİK AYARLARI ---
const int numFeatures = 20; 
float baselineCurve[numFeatures]; 

// --- SÜPER GÜÇLER ---
const int pulseWidth = 50;       // Demiri yakalamak için uzun şarj (50us)
const int oversampleCount = 10;  // Çevresel gürültüyü ütülemek için 10x okuma

const int sensitivityOffset = 15; // LED'in yanması için gereken çöküş eşiği
const int beklemeSuresi = 50; 

// --- PREDICTION SMOOTHING (KARARLILIK) ---
const int READINGS_NEEDED = 3; // Değiştirebilirsiniz (örn. 5 veya 6)
int previousPrediction = -1;
int consecutiveCount = 0;

// --- ANA OKUMA MOTORU (OVERSAMPLING) ---
void sarmalOkuVeOrtalamaAl(float* hedefDizi) {
  long toplamlar[numFeatures] = {0};
  
  for(int k = 0; k < oversampleCount; k++) {
    // Reset capacitor
    pinMode(readPin, OUTPUT); 
    digitalWrite(readPin, LOW); 
    delayMicroseconds(50); 
    pinMode(readPin, INPUT);
    
    portDISABLE_INTERRUPTS();
    digitalWrite(pulsePin, HIGH); 
    delayMicroseconds(pulseWidth); 
    digitalWrite(pulsePin, LOW);
    
    delayMicroseconds(15);  // ← FIX 1: blanking time, skip flyback spike
    
    for(int i = 0; i < numFeatures; i++) {
      toplamlar[i] += analogRead(readPin);
      delayMicroseconds(30);  // ← FIX 2: capture actual decay shape
    }
    portENABLE_INTERRUPTS();
    delay(5);
  }
  
  for(int i = 0; i < numFeatures; i++) {
    hedefDizi[i] = (float)toplamlar[i] / oversampleCount;
  }
}
// Call this after sarmalOkuVeOrtalamaAl() collects data
// Call this after sarmalOkuVeOrtalamaAl() collects data
void classifyMetal(float* okumalar) {
  // Only delta features now
  float fark[20];
  for (int i = 0; i < 20; i++) {
    float d = baselineCurve[i] - okumalar[i];
    fark[i] = (d < 0) ? 0.0f : d;
  }

  float features[61];
  float epsilon = 1e-6f;

  // 1. Raw delta (20)
  for (int i = 0; i < 20; i++) features[i] = fark[i];

  // 2. Normalized shape (20)
  for (int i = 0; i < 20; i++) features[20 + i] = fark[i] / (fark[0] + epsilon);

  // 3. Slopes (19)
  for (int i = 0; i < 19; i++) features[40 + i] = fark[i + 1] - fark[i];

  // 4. Energy (1)
  float energy = 0;
  for (int i = 0; i < 20; i++) energy += fark[i];
  features[59] = energy;

  // 5. Decay rate (1)
  float early = (fark[0] + fark[1] + fark[2]) / 3.0f;
  float late  = (fark[17] + fark[18] + fark[19]) / 3.0f;
  features[60] = early - late;

  float confidence = 0.0f;
  int predictedClass = predictMetal(features, &confidence);

  // --- YENİ EKLENEN YER BURASI ---
  if (confidence < CONFIDENCE_THRESHOLD) {
    // If confidence is low, reset the counter so we don't accidentally 
    // connect old readings with new ones
    consecutiveCount = 0;
    previousPrediction = -1;
  } else {
    // If the new prediction matches the last one, increase the count
    if (predictedClass == previousPrediction) {
      consecutiveCount++;
    } else {
      // If it changed, reset the count to 1 and track the new prediction
      consecutiveCount = 1;
      previousPrediction = predictedClass;
    }

    // Only print if we hit our target count (e.g., 5 times in a row)
    if (consecutiveCount >= READINGS_NEEDED && previousPrediction != -1) {
      Serial.print("Metal: ");
      Serial.print(CLASS_LABELS[previousPrediction]);
      Serial.print(" (");
      Serial.print(confidence * 100, 1);
      Serial.println("%)");
      
      // Reset the count so it doesn't spam the serial monitor continuously
      consecutiveCount = 0; 
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF); 
  
  pinMode(pulsePin, OUTPUT);
  pinMode(readPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(alarmPin, OUTPUT); 
  
  digitalWrite(pulsePin, LOW);
  digitalWrite(alarmPin, LOW);
  
  delay(2000); 
  Serial.println(">>> CIHAZ BASLATILDI - TEK LED MODU <<<");
  
  // 1. Isınma Turu
  float copDizi[numFeatures];
  for(int i = 0; i < 5; i++) { sarmalOkuVeOrtalamaAl(copDizi); delay(50); }
  
  // 2. Boşluk (Referans) Kalibrasyonu
  long baselineToplami[numFeatures] = {0};
  for(int k = 0; k < 50; k++) {
    float anlikEgri[numFeatures];
    sarmalOkuVeOrtalamaAl(anlikEgri);
    for(int i = 0; i < numFeatures; i++) { baselineToplami[i] += anlikEgri[i]; }
    delay(20);
  }
  for(int i = 0; i < numFeatures; i++) { baselineCurve[i] = (float)baselineToplami[i] / 50.0; }
  
  Serial.println("--- KALIBRASYON TAMAM ---");
  
  // CSV Başlıklarını Yazdır (20 Ham + 20 Fark)
  for(int i=0; i<numFeatures; i++) { Serial.print("raw_t"); Serial.print(i); Serial.print(","); }
  for(int i=0; i<numFeatures; i++) { Serial.print("fark_t"); Serial.print(i); if(i < numFeatures - 1) Serial.print(","); }
  Serial.println();
}

void loop() {
  // --- NORMAL İZLEME (RADAR) MODU ---
  float okumalar[numFeatures];
  sarmalOkuVeOrtalamaAl(okumalar);

  // LED için ilk 3 noktanın ortalama çöküşüne bak
  float fark0 = baselineCurve[0] - okumalar[0];
  float fark1 = baselineCurve[1] - okumalar[1];
  float fark2 = baselineCurve[2] - okumalar[2];
  float ortalamaCokus = (fark0 + fark1 + fark2) / 3.0;
  
  // Sadece metali algıladığında yanar
if (ortalamaCokus > sensitivityOffset) {
    digitalWrite(alarmPin, HIGH);
    classifyMetal(okumalar);  // ← ADD THIS LINE
} else {
    digitalWrite(alarmPin, LOW);
}

  // --- 5 SANİYELİK OTOMATİK VERİ KAYIT MODU ---
  if (digitalRead(buttonPin) == LOW) {
    delay(20); // Debounce
    if (digitalRead(buttonPin) == LOW) { 
      
      unsigned long baslangicZamani = millis();
      
      while (millis() - baslangicZamani < 5000) {
        
        float seriOkumalar[numFeatures];
        sarmalOkuVeOrtalamaAl(seriOkumalar);
        
        // KAYIT SIRASINDA DA LED'İN DOĞRU ÇALIŞMASI İÇİN GÜNCELLE
        float anlikFark0 = baselineCurve[0] - seriOkumalar[0];
        float anlikFark1 = baselineCurve[1] - seriOkumalar[1];
        float anlikFark2 = baselineCurve[2] - seriOkumalar[2];
        float anlikCokus = (anlikFark0 + anlikFark1 + anlikFark2) / 3.0;
        
        if (anlikCokus > sensitivityOffset) {
          digitalWrite(alarmPin, HIGH);
        } else {
          digitalWrite(alarmPin, LOW);
        }

        // 1. KISIM: 20 Ham Veriyi Yazdır
        for(int i = 0; i < numFeatures; i++) {
          Serial.print(seriOkumalar[i], 1); 
          Serial.print(",");
        }

        // 2. KISIM: 20 Fark (Delta) Verisini Yazdır
        for(int i = 0; i < numFeatures; i++) {
          float fark = baselineCurve[i] - seriOkumalar[i];
          if (fark < 0) fark = 0.0; // Negatif gürültüleri sıfıra kilitle
          Serial.print(fark, 1); 
          if(i < numFeatures - 1) Serial.print(",");
        }
        Serial.println(); 
        
        delay(30); 
      }
      
      // Kullanıcı elini butondan çekene kadar sistemi beklet
      while (digitalRead(buttonPin) == LOW) { delay(10); }
    }
  }
  
  delay(beklemeSuresi); 
}