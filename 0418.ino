// 定義腳位
const int potPin = A0;    // 可變電阻接在 A0 腳位
const int ledPin = 9;     // LED 接在 9 號腳位（PWM 輸出）

void setup() {
  // 初始化序列通訊
  Serial.begin(9600);
  
  // 設定 LED 腳位為輸出
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 讀取可變電阻的類比值 (0-1023)
  int potValue = analogRead(potPin);
  
  // 將可變電阻的值映射到 LED 亮度範圍 (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // 控制 LED 亮度
  analogWrite(ledPin, brightness);
  
  // 將類比值轉換為電壓值 (0-5V)
  float voltage = potValue * (5.0 / 1023.0);
  
  // 透過序列埠輸出資訊
  Serial.print("類比值: ");
  Serial.print(potValue);
  Serial.print(" | 電壓: ");
  Serial.print(voltage, 2);
  Serial.print("V | LED 亮度: ");
  Serial.println(brightness);
  
  // 延遲一小段時間
  delay(100);
}