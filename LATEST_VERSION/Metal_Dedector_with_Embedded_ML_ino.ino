#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "rf_model.h" // ML Modelimizi dahil ediyoruz

// =====================================================
// [!] VERI TOPLAMA ETIKETI (DATA LABEL)
// =====================================================
const String TARGET_METAL = "PreciousMetals"; 

// =====================================================
// [!] TAHMİN İSİMLERİ (Sınıflar)
// =====================================================
const int NUM_CLASSES = 5;
const String metalNames[NUM_CLASSES] = {"Aluminium", "Copper",  "NonMetal", "PreciousMetals" ,"Steel"};

// =====================================================
// DONANIM PINLERI
// =====================================================
const int pulsePin = 32;
const int readPin  = 33;
const int alarmPin = 25;

const int BOOT_BUTTON = 0; 

#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

const long frekanslar[3] = {10000, 40000, 80000};

float filteredValues[3] = {0, 0, 0};
float baselineValues[3] = {0, 0, 0};
float thresholds[3]     = {0, 0, 0};

float filterAlpha = 0.05;
const int sensitivityOffset = 15;
const int beklemeSuresi = 50;

int currentMenuOption = 1; 

// =====================================================
// SENSOR OKUMA VE FILTRELEME
// =====================================================
float readSignal(int freqIndex) {
  long rawSum = 0;
  int numSamples = 16;
  int pulseDelay = 1000000 / frekanslar[freqIndex] / 2;
  int okumaGecikmesi[3] = {15, 8, 2};

  for (int i = 0; i < numSamples; i++) {
    pinMode(readPin, OUTPUT);
    digitalWrite(readPin, LOW);
    delayMicroseconds(50);
    pinMode(readPin, INPUT);

    portDISABLE_INTERRUPTS();
    digitalWrite(pulsePin, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(pulsePin, LOW);

    delayMicroseconds(okumaGecikmesi[freqIndex]);
    int currentRaw = analogRead(readPin);
    portENABLE_INTERRUPTS();

    rawSum += currentRaw;
    delayMicroseconds(100);
  }
  return (float)rawSum / numSamples;
}

float veriyiFiltrele(int freqIndex, float hamOkuma) {
  filteredValues[freqIndex] = (filterAlpha * hamOkuma) + ((1.0 - filterAlpha) * filteredValues[freqIndex]);
  return filteredValues[freqIndex];
}

void donanimKalibrasyonu() {
  Serial.println(">>> CALIBRATION BEGINS (Make sure there is no metal around the coil!) <<<");
  
  for (int i = 0; i < 20; i++) {
    readSignal(0); readSignal(1); readSignal(2);
    delay(beklemeSuresi);
  }

  float calSums[3] = {0, 0, 0};
  int calSamples = 50;

  for (int i = 0; i < calSamples; i++) {
    calSums[0] += readSignal(0);
    calSums[1] += readSignal(1);
    calSums[2] += readSignal(2);
    delay(beklemeSuresi);
  }

  for (int f = 0; f < 3; f++) {
    baselineValues[f] = calSums[f] / calSamples;
    thresholds[f] = baselineValues[f] - sensitivityOffset;
    filteredValues[f] = baselineValues[f];
  }
  Serial.println("--- CALIBRATION COMPLETE ---");
}

// =====================================================
// LCD + BOOT BUTON KONTROLU
// =====================================================
void updateLCDMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (currentMenuOption == 1) {
    lcd.print("> 1:Start Calibration");
  } else if (currentMenuOption == 2) {
    lcd.print("> 2:Collect Data");
  } else if (currentMenuOption == 3) {
    lcd.print("> 3:Prediction Test");
  }
  lcd.setCursor(0, 1); 
  lcd.print("Short:Skip Long:Choose");
}

int checkBootButton() {
  static unsigned long buttonPressTime = 0;
  static bool isPressing = false;
  static bool longPressTriggered = false;
  int action = 0; 

  int reading = digitalRead(BOOT_BUTTON);

  if (reading == LOW) { 
    if (!isPressing) {
      isPressing = true;
      buttonPressTime = millis();
      longPressTriggered = false;
    } 
    else if (!longPressTriggered && (millis() - buttonPressTime > 1000)) {
      action = 2; 
      longPressTriggered = true; 
    }
  } 
  else { 
    if (isPressing) {
      if (!longPressTriggered && (millis() - buttonPressTime > 50)) {
        action = 1; 
      }
      isPressing = false;
    }
  }
  return action;
}

// =====================================================
// SETUP
// =====================================================
void setup() {
  Serial.begin(115200);

  pinMode(pulsePin, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  digitalWrite(pulsePin, LOW);
  digitalWrite(alarmPin, LOW);
  
  pinMode(BOOT_BUTTON, INPUT_PULLUP);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Starting");
  delay(1000); 
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibration...");
  donanimKalibrasyonu();

  updateLCDMenu();
}

// =====================================================
// LOOP
// =====================================================
void loop() {
  int buttonAction = checkBootButton();

  if (buttonAction == 1) {
    currentMenuOption++;
    if (currentMenuOption > 3) currentMenuOption = 1;
    updateLCDMenu();
  }
  else if (buttonAction == 2) {
    
    // --- OPSIYON 1: KALİBRASYON ---
    if (currentMenuOption == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      //lcd.print("Calibration...");
      donanimKalibrasyonu();
      //lcd.clear(); lcd.setCursor(0, 0); lcd.print("Calibration OK!");
      delay(1000);
      updateLCDMenu();
    }
    
    // --- OPSIYON 2: VERİ TOPLAMA ---
    else if (currentMenuOption == 2) {
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("Collecting Data:");
      lcd.setCursor(0, 1); lcd.print(TARGET_METAL);

      //Serial.println("Label,10kHz,40kHz,80kHz"); 

      for (int i = 1; i <= 100; i++) {
        float val10k = veriyiFiltrele(0, readSignal(0));
        float val40k = veriyiFiltrele(1, readSignal(1));
        float val80k = veriyiFiltrele(2, readSignal(2));
        
        Serial.printf("%s,%.1f,%.1f,%.1f\n", TARGET_METAL.c_str(), val10k, val40k, val80k);
        delay(beklemeSuresi);
      }
      
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("RECORD OK!");
      delay(1500);
      updateLCDMenu();
    }

    // --- OPSIYON 3: TAHMİN / CANLI TEST MODU ---
    else if (currentMenuOption == 3) {
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("Live Prediction:");
      Serial.println("\n--- LIVE PREDICTION MODE STARTING (10 Seconds Active) ---");

      unsigned long startTime = millis();
      
      // Oyları tutacağımız dizi (Her metal için 0'dan başlıyor)
      int tahminOylari[NUM_CLASSES] = {0}; 
      
      while (millis() - startTime < 10000) {
        
        for (int f = 0; f < 3; f++) {
          veriyiFiltrele(f, readSignal(f));
        }

        int16_t features[3];
        features[0] = (int16_t)filteredValues[0];
        features[1] = (int16_t)filteredValues[1];
        features[2] = (int16_t)filteredValues[2];

        int sonuc_id = rf_model_predict(features, 3);

        String tahminEdilenMetal = "Unknown";
        if (sonuc_id >= 0 && sonuc_id < NUM_CLASSES) {
          tahminEdilenMetal = metalNames[sonuc_id];
          tahminOylari[sonuc_id]++; // Hangi metal tahmin edildiyse onun oyunu 1 artır
        }

        lcd.setCursor(0, 1);
        lcd.print(tahminEdilenMetal);
        lcd.print("        "); 

        Serial.printf(">> Prediction: %s | 10k:%.1f | 40k:%.1f | 80k:%.1f\n", 
                      tahminEdilenMetal.c_str(), filteredValues[0], filteredValues[1], filteredValues[2]);

        delay(150); 
      }

      Serial.println("--- PREDICTION MODE COMPLETE ---");
      
      // En çok oy alan metali bulma
      int enYuksekOy = 0;
      int kazananMetalID = -1;
      
      for(int i = 0; i < NUM_CLASSES; i++) {
        if(tahminOylari[i] > enYuksekOy) {
          enYuksekOy = tahminOylari[i];
          kazananMetalID = i;
        }
      }

      // Sonucu LCD'ye yazdır ve 5 saniye bekle
      lcd.clear();
      lcd.setCursor(0, 0); 
      lcd.print("Test Complete.");
      
      if(kazananMetalID != -1) {
        lcd.setCursor(0, 1); 
        lcd.print("Result: ");
        lcd.print(metalNames[kazananMetalID]);
        Serial.printf("--- MOST PREDICTED: %s (%d times) ---\n", metalNames[kazananMetalID].c_str(), enYuksekOy);

        // --- ALARM/SES MANTIĞI ---
        // Eğer kazanan metal "NonMetal" değilse alarm çal
        // --- ALARM/SES MANTIĞI ---
        if (metalNames[kazananMetalID] != "NonMetal") {
          
          // 3 kere art arda BİP sesi ver (Pasif Buzzer için tone() kullanılır)
          for(int i = 0; i < 3; i++) {
            tone(alarmPin, 2000); // 2000 Hz frekansında ses ver
            delay(200);
            noTone(alarmPin);     // Sesi sustur
            delay(200);
          }
          
          delay(3800); 
          
        } else {
          delay(5000); 
        }

      } else {
        lcd.setCursor(0, 1); 
        lcd.print("No Data");
        delay(5000);
      }
 
      
      delay(5000); // 5 saniye boyunca ekranda tut
      updateLCDMenu();
    }
  }

  // Arka planda okumaya devam et ki filtreler (EMA) sıcak/güncel kalsın
  for (int f = 0; f < 3; f++) {
     veriyiFiltrele(f, readSignal(f));
  }
  delay(10);
}