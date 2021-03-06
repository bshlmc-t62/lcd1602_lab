//This lab use DHT11 to test environent temperature and humidity.
//Results will display using LCD and Serial Monitor
//Connect Vcc - 5V, GND - 0V, Signal - D3
//Connect LCD1602(I2C) to 5V, GND, SDA, SDL

#include <dht.h>
#include <LiquidCrystal_I2C.h>
#define DHT11_PIN 3  // change the pin number if you want
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 設定 LCD I2C 位址
dht DHT;
String s1 = "BSHLMC";
String s2 = "www.bshlmc.edu.hk";


void setup() {

  //Initial Serial Monitor
  Serial.begin(9600);
  Serial.println(s1); 

  //Initial I2C LCD 1602
  lcd.begin(16, 2); // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print(s1);
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print(s2);
  for(int i = 0; i < 1; i++) {
    lcd.backlight(); // 開啟背光
    delay(250);
    lcd.noBacklight(); // 關閉背光
    delay(250);
    }
  lcd.backlight();
  }

void loop() { // READ DATA

int chk = DHT.read11(DHT11_PIN);

//Display Serial Monitor
Serial.println("Humidity " );
Serial.println(DHT.humidity, 1);
Serial.println("Temparature ");
Serial.println(DHT.temperature, 1);

//Display LCD
  lcd.clear();
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("Humidity ");
  lcd.print(DHT.humidity, 1);
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("Temparature ");
  lcd.print(DHT.temperature, 1);

delay(2000);

}
