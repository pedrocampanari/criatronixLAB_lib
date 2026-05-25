#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 11  // pino do DHT22
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4);  // endereço comum: 0x27

void setup() {
  lcd.init();
  lcd.backlight();

  dht.begin();

  lcd.setCursor(3, 1);
  lcd.print("Criatronix Lab");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.println(hum);
  lcd.setCursor(0, 0);
  lcd.print("Temperatura Umidade");
  lcd.setCursor(3, 2);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C   ");

  lcd.setCursor(3, 3);
  lcd.print("Umid: ");
  lcd.print(hum);
  lcd.print(" %   ");

  delay(2000);
}