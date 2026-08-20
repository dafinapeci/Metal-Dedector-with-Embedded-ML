# AI-Assisted Multi Metal Detector & Classifier EN / TR

*(Scroll down for the Turkish version / Türkçe sürüm için aşağı kaydırın)*

---

## EN - English Version

This repository contains the software and hardware integration codes for an **AI-Assisted Pulse Induction (PI) Metal Detector** built on the ESP32 microcontroller. The system uses **10x Oversampling** and a **50µs pulse width** to extract pure decay curves free from environmental noise, making it highly suitable for Machine Learning training and inference.

### 🚀 What's New in This Version?
Based on recent hardware and signal processing optimizations, the system architecture has been significantly upgraded:
*   **Multi-Frequency Sampling:** The ESP32 now sends pulses and reads analog responses at three distinct frequencies: **10kHz, 40kHz, and 80kHz**.
*   **Expanded ML Model:** The Random Forest Classifier (trained via `scikit-learn` and exported to raw C code using `m2cgen`) now supports **5 classes** with an accuracy of **90.18%**:
    1. Aluminium
    2. Copper
    3. NonMetal
    4. PreciousMetals
    5. Steel
*   **Interactive LCD Menu:** Replaced the hardcoded modes with an interactive menu navigated using the ESP32's onboard BOOT button.

### 🛠 Hardware & Pin Connections
To ensure the system works correctly, connect your components to the ESP32 as follows:
*   **Pin 32 (OUTPUT):** Pulse pin connected to the MOSFET gate to drive the coil.
*   **Pin 33 (INPUT):** Analog (ADC) read pin to capture the decay curve (voltage) from the coil.
*   **Pin 0 (INPUT_PULLUP):** Onboard BOOT button used for menu navigation.
*   **Pin 25 (OUTPUT):** Alarm/Radar LED (Turns on/beeps when the metal threshold is crossed).
*   **Pins 21 & 22 (I2C):** SDA and SCL pins for the 1602A I2C LCD Display.

### 🚀 ESP32 Installation & Upload Steps
If you want to run this project on your computer and upload it to the ESP32, follow these steps:
1.  **Install Required Software:** Download and install the Arduino IDE.
2.  Open the Arduino IDE and go to **File > Preferences**.
3.  Paste the following link into the **"Additional Boards Manager URLs"** field:
    `https://dl.espressif.com/dl/package_esp32_index.json`
4.  Go to **Tools > Board > Boards Manager**, search for `esp32`, and install the package by Espressif Systems.
5.  **Compile and Upload:** Connect your ESP32 to the computer via USB.
6.  Select **"ESP32 Dev Module"** from **Tools > Board**.
7.  Select the correct COM port from **Tools > Port**.
8.  Click the **Upload** button (Left arrow icon). *(Note: If the screen says "Connecting..." during the upload, press and hold the BOOT button on the ESP32 for a few seconds).*

### 📊 Usage and Data Collection (How it Works)
Once the code is uploaded, open the **Serial Monitor** in the top right corner of the Arduino IDE. Make sure the **Baud Rate is set to 115200**.

You can navigate the LCD menu using the ESP32's BOOT button:
*   **Short Press:** Skip to the next menu option.
*   **Long Press (>1 sec):** Choose the selected option.

**Operation Modes:**
1.  **Start Calibration:** Samples the environment 50 times to establish a "No Metal" baseline. *(Make sure there is no metal around the coil during this process!)*
2.  **Collect Data:** Automatically captures 100 samples (at 10kHz, 40kHz, 80kHz) and prints them in CSV format to the Serial Monitor. Ideal for gathering new data to retrain the ML model. Copy this flowing data and save it as a `.csv` file for Edge Impulse or custom Python training.
3.  **Live Prediction Test:** Runs a 10-second active scanning window. The ESP32 continuously samples the coil, runs the embedded Random Forest model (`rf_model_predict`), and prints real-time classifications to the LCD. At the end of the 10 seconds, the majority vote wins and triggers the alarm if a metal is confirmed.

---

## TR - Türkçe Sürüm

Bu depo, Makine Öğrenmesi (Machine Learning) tabanlı bir Pulse Induction (PI) metal dedektörü geliştirmek amacıyla tasarlanan veri toplama ve sınıflandırma yazılımını içermektedir. Sistem, ESP32 mikrodenetleyicisi üzerinde çalışır ve çevresel gürültülerden arındırılmış, yapay zeka eğitimine uygun saf sönümleme (decay) eğrileri elde etmek için **10x Oversampling (Yüksek Örnekleme)** ve **50us darbe süresi (Pulse Width)** tekniklerini kullanır.

### 🚀 Bu Sürümdeki Yenilikler
Son donanım ve sinyal işleme optimizasyonlarına dayanarak sistem mimarisinde önemli güncellemeler yapılmıştır:
*   **Çoklu Frekans (Multi-Frequency) Örnekleme:** Sistem artık tek bir okuma yerine; **10kHz, 40kHz ve 80kHz** olmak üzere üç farklı frekansta sinyal gönderip okuma yapmaktadır.
*   **Genişletilmiş ML Modeli:** `scikit-learn` ile eğitilip `m2cgen` kullanılarak doğrudan C koduna çevrilen Random Forest (Rastgele Orman) modeli, artık **%90.18** doğruluk oranıyla **5 farklı sınıfı** tanımaktadır:
    1. Aluminium (Alüminyum)
    2. Copper (Bakır)
    3. NonMetal (Metal Değil / Boşluk)
    4. PreciousMetals (Değerli Metaller)
    5. Steel (Çelik)
*   **İnteraktif LCD Menü:** ESP32 üzerindeki BOOT butonu ile kontrol edilebilen interaktif bir menü sistemine geçilmiştir.

### 🛠 Donanım ve Pin Bağlantıları
Projenin sorunsuz çalışması için ESP32 üzerindeki bağlantıların aşağıdaki gibi yapılması gerekmektedir:
*   **Pin 32 (OUTPUT):** Bobine sinyal gönderen MOSFET'in Gate (Tetik) pini.
*   **Pin 33 (INPUT):** Bobindeki sönümleme eğrisini (voltajı) okuyan Analog (ADC) pin.
*   **Pin 0 (INPUT_PULLUP):** ESP32 üzerindeki dâhili BOOT butonudur. Menüde gezinmek için kullanılır.
*   **Pin 25 (OUTPUT):** Metal Algılama (Radar) Alarm LED'i (Sadece metal eşiği geçildiğinde yanar/öter).
*   **Pin 21 & 22 (I2C):** 1602A I2C LCD ekran için SDA ve SCL haberleşme pinleri.

### 🚀 Kodu ESP32'ye Yükleme Adımları (Kurulum)
Eğer bu projeyi bilgisayarınızda çalıştırmak ve ESP32'ye yüklemek istiyorsanız şu adımları izleyin:
1.  **Gerekli Yazılımları Kurun:** Bilgisayarınıza Arduino IDE'yi indirin ve kurun.
2.  Arduino IDE'yi açın, **Dosya > Tercihler (File > Preferences)** sekmesine gidin.
3.  **"Ek Kart Yöneticisi URL'leri"** kısmına şu linki yapıştırın:
    `https://dl.espressif.com/dl/package_esp32_index.json`
4.  **Araçlar > Kart > Kart Yöneticisi (Tools > Board > Boards Manager)** menüsünü açın, `esp32` yazıp aratın ve Espressif Systems tarafından hazırlanan paketi kurun.
5.  **Kodu Derleme ve Yükleme:** ESP32'yi bilgisayarınıza USB kablosu ile bağlayın.
6.  Arduino IDE'de Araçlar > Kart menüsünden **"ESP32 Dev Module"** seçeneğini seçin.
7.  Araçlar > Port menüsünden cihazınızın bağlı olduğu COM portunu seçin.
8.  Sol üstteki ok işaretine (Yükle / Upload) basarak kodu cihaza gönderin. *(Not: Yükleme sırasında ekranda "Connecting..." yazısı çıkarsa ESP32 üzerindeki BOOT tuşuna birkaç saniye basılı tutun).*

### 📊 Kullanım ve Veri Toplama (Nasıl Çalışır?)
Kod yüklendikten sonra Arduino IDE'nin sağ üst köşesindeki **Seri Port Ekranı'nı (Serial Monitor)** açın. **Baud Rate ayarını sağ alt köşeden 115200** olarak seçtiğinizden emin olun.

Menüde ESP32'nin BOOT butonu ile gezinebilirsiniz:
*   **Kısa Basım:** Bir sonraki menü seçeneğine atlar.
*   **Uzun Basım (>1 sn):** Ekranda görünen seçeneği onaylar.

**Çalışma Modları:**
1.  **Start Calibration (Kalibrasyon):** Ortamda metal yokken 50 örnek alarak "Boşluk" (Baseline) değerini belirler. *(Bu süre zarfında bobine herhangi bir metal yaklaştırmayın!)*
2.  **Collect Data (Veri Toplama):** Seçilen metal için 10kHz, 40kHz ve 80kHz frekanslarında art arda 100 örnek alarak Seri Port ekranına CSV formatında (Virgülle ayrılmış) yazdırır. Modeli yeniden eğitmek için yeni veri setleri oluşturmada kullanılır. Ekrana akan bu verileri kopyalayıp bir `.csv` dosyası olarak kaydederek makine öğrenmesi modelinizi eğitebilirsiniz.
3.  **Live Prediction Test (Canlı Tahmin):** 10 saniyelik aktif tarama penceresi başlatır. ESP32 sürekli olarak bobini örnekler, gömülü ML modelini (`rf_model_predict`) çalıştırır ve sonuçları LCD'de anlık olarak gösterir. 10 saniye sonunda en çok oy alan sınıf ekrana yazdırılır ve tespit edilen obje metal ise alarm tetiklenir.
