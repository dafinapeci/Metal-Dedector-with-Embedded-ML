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

// --- ANA OKUMA MOTORU (OVERSAMPLING) ---
void sarmalOkuVeOrtalamaAl(float* hedefDizi) {
  long toplamlar[numFeatures] = {0}; 
  
  for(int k = 0; k < oversampleCount; k++) {
    // Kapasitörü Sıfırla
    pinMode(readPin, OUTPUT); digitalWrite(readPin, LOW); delayMicroseconds(50); pinMode(readPin, INPUT); 
    
    // Darbeyi Gönder
    portDISABLE_INTERRUPTS();
    digitalWrite(pulsePin, HIGH); delayMicroseconds(pulseWidth); digitalWrite(pulsePin, LOW);
    
    // Hızlıca 20 noktayı oku
    for(int i = 0; i < numFeatures; i++) {
      toplamlar[i] += analogRead(readPin);
      delayMicroseconds(30); 
    }
    portENABLE_INTERRUPTS();
    delay(5); 
  }
  
  // Ortalamayı al
  for(int i = 0; i < numFeatures; i++) {
    hedefDizi[i] = (float)toplamlar[i] / oversampleCount;
  }
}

// Call this after sarmalOkuVeOrtalamaAl() collects data
void classifyMetal(float* okumalar) {
  float features[40];
  for (int i = 0; i < 20; i++) features[i] = okumalar[i];
  for (int i = 0; i < 20; i++) {
    float delta = baselineCurve[i] - okumalar[i];
    features[20 + i] = (delta < 0) ? 0.0f : delta;
  }

  // ── FERROUS PRE-CHECK ──────────────────────────────
  // Steel/iron: inductance SLOWS the early decay.
  // So raw_t0 stays relatively HIGH vs raw_t5
  float earlyAvg = (features[0] + features[1] + features[2]) / 3.0f;
  float lateAvg  = (features[4] + features[5] + features[6]) / 3.0f;
  float slope    = earlyAvg - lateAvg;  // steeper = non-ferrous
  
  // You need to tune this threshold from your actual data
  // Print slope for steel vs aluminium to find the boundary
  Serial.print("Slope: "); Serial.println(slope);
  // if (slope < YOUR_THRESHOLD) { Serial.println("Ferrous (Steel/Iron)"); return; }
  // ──────────────────────────────────────────────────


  
  float confidence = 0.0f;
  int predictedClass = predictMetal(features, &confidence);
  // ... rest unchanged

  // Display result
  if (confidence < CONFIDENCE_THRESHOLD) {
    Serial.println("Unknown / Low confidence");
    // lcd.print("Unknown");
  } else {
    Serial.print("Metal: ");
    Serial.print(CLASS_LABELS[predictedClass]);
    Serial.print(" (");
    Serial.print(confidence * 100, 1);
    Serial.println("%)");
    // lcd.print(CLASS_LABELS[predictedClass]);
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