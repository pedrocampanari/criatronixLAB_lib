#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define sensorUmidade A2
#define pinLEDRGB_Green 7
#define pinLEDRGB_Red 8
#define buzzer 2

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(A2, INPUT);
  Serial.begin(9600);

  lcd.setCursor(3, 1);
  lcd.print("Criatronix Lab");
  delay(2000);
  lcd.clear();

  pinMode(pinLEDRGB_Green, OUTPUT);
  pinMode(pinLEDRGB_Red, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int leituraUmidade = analogRead(sensorUmidade);

  if (leituraUmidade <= 700) {  
    lcd.setCursor(0, 1);
    lcd.print("    Planta Regada    ");
    digitalWrite(pinLEDRGB_Red, LOW);
    digitalWrite(pinLEDRGB_Green, HIGH);

  } else {
    lcd.setCursor(2, 1);
    lcd.print("Rega Nescessaria");
    digitalWrite(pinLEDRGB_Red, HIGH);
    digitalWrite(pinLEDRGB_Green, LOW);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(pinLEDRGB_Red, LOW);
    digitalWrite(pinLEDRGB_Green, LOW);
     digitalWrite(buzzer, LOW);
    delay(1000);
   
  }
}
