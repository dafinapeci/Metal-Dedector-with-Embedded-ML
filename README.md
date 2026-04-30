İşte hiçbir takım veya proje ismi içermeyen, tamamen teknik ve amaca yönelik o saf README dosyası. Doğrudan kopyalayıp kullanabilirsin:

🎯 PI (Pulse Induction) Metal Dedektörü - Veri Toplama Sistemi (v1.0)
Bu depo, Makine Öğrenmesi (Machine Learning) tabanlı bir Pulse Induction (PI) metal dedektörü geliştirmek amacıyla tasarlanan veri toplama yazılımını içermektedir.

Sistem, ESP32 mikrodenetleyicisi üzerinde çalışır ve çevresel gürültülerden arındırılmış, yapay zeka eğitimine uygun saf sönümleme (decay) eğrileri elde etmek için 10x Oversampling (Yüksek Örnekleme) ve 50us darbe süresi (Pulse Width) tekniklerini kullanır.

🛠 Donanım ve Pin Bağlantıları
Projenin sorunsuz çalışması için ESP32 üzerindeki bağlantıların aşağıdaki gibi yapılması gerekmektedir:

Pin 32 (OUTPUT): Bobine sinyal gönderen MOSFET'in Gate (Tetik) pini.

Pin 33 (INPUT): Bobindeki sönümleme eğrisini (voltajı) okuyan Analog (ADC) pin.

Pin 0 (INPUT_PULLUP): ESP32 üzerindeki dâhili BOOT butonudur. 5 saniyelik seri veri kaydını başlatmak için kullanılır.

Pin 25 (OUTPUT): Metal Algılama (Radar) Alarm LED'i (Sadece metal eşiği geçildiğinde yanar).

🚀 Kodu ESP32'ye Yükleme Adımları (Kurulum)
Eğer bu projeyi bilgisayarınızda çalıştırmak ve ESP32'ye yüklemek istiyorsanız şu adımları izleyin:

1. Gerekli Yazılımları Kurun
Bilgisayarınıza Arduino IDE'yi indirin ve kurun.

Arduino IDE'yi açın, Dosya > Tercihler (File > Preferences) sekmesine gidin.

"Ek Kart Yöneticisi URL'leri" kısmına şu linki yapıştırın:
[https://dl.espressif.com/dl/package_esp32_index.json](https://dl.espressif.com/dl/package_esp32_index.json)

Araçlar > Kart > Kart Yöneticisi (Tools > Board > Boards Manager) menüsünü açın, esp32 yazıp aratın ve Espressif Systems tarafından hazırlanan paketi kurun.

2. Kodu Derleme ve Yükleme
Bu depodaki .ino dosyasını indirin veya kopyalayın.

Klasör adının ve dosya adının birebir aynı olduğundan emin olun (Örn: Veri_Toplama/Veri_Toplama.ino).

ESP32'yi bilgisayarınıza USB kablosu ile bağlayın.

Arduino IDE'de Araçlar > Kart menüsünden "ESP32 Dev Module" seçeneğini seçin.

Araçlar > Port menüsünden cihazınızın bağlı olduğu COM portunu seçin.

Sol üstteki ok işaretine (Yükle / Upload) basarak kodu cihaza gönderin. (Not: Yükleme sırasında ekranda "Connecting..." yazısı çıkarsa ESP32 üzerindeki BOOT tuşuna birkaç saniye basılı tutun).

📊 Kullanım ve Veri Toplama (Nasıl Çalışır?)
Kod yüklendikten sonra Arduino IDE'nin sağ üst köşesindeki Seri Port Ekranı'nı (Serial Monitor) açın.

Baud Rate ayarını sağ alt köşeden 115200 olarak seçtiğinizden emin olun.

Cihaza güç verildiğinde veya resetlendiğinde sistem otomatik olarak Çevresel Boşluk Kalibrasyonu yapar. Bu süre zarfında (yaklaşık 3-4 saniye) bobine herhangi bir metal yaklaştırmayın.

Normal Mod (Radar): Kalibrasyon bittikten sonra metali yaklaştırdığınızda Pin 25'e bağlı LED yanarak tepki verecektir.

Kayıt Modu: Edge Impulse veya başka bir yapay zeka platformu için veri toplamak istediğinizde, metali sabit bir açıda tutun ve ESP32 üzerindeki BOOT tuşuna bir kez basıp bırakın.

Sistem 5 saniye boyunca saniyede ~12-15 satır olmak üzere CSV formatında (Virgülle ayrılmış) ham ve delta verilerini Seri Port ekranına basacaktır.

Ekrana akan bu verileri kopyalayıp bir .csv dosyası olarak kaydederek makine öğrenmesi modelinizi eğitebilirsiniz.
