#include <Servo.h>
#include <IRremote.hpp>


#define pinRecIR 12
#define pinServoMotor 3
#define pinLed_Green A3
#define pinLed_Red A4
#define pinLed_Yellow A5
#define pinLEDRGB_Blue 4
#define pinLEDRGB_Green 7
#define pinLEDRGB_Red 8
#define pinServo 3

Servo servoMotor;
byte grauServo = 0;

void setup() {
  pinMode(pinLed_Green, OUTPUT);
  pinMode(pinLed_Red, OUTPUT);
  pinMode(pinLed_Yellow, OUTPUT);
  pinMode(pinLEDRGB_Green, OUTPUT);
  pinMode(pinLEDRGB_Red, OUTPUT);
  pinMode(pinLEDRGB_Blue, OUTPUT);

  Serial.begin(9600);
  IrReceiver.begin(pinRecIR, ENABLE_LED_FEEDBACK);
  servoMotor.attach(pinServoMotor);
  servoMotor.write(grauServo);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long IRCode = IrReceiver.decodedIRData.decodedRawData;

    Serial.println(IRCode);
    IrReceiver.resume();

    switch (IRCode) {
      case 4077715200:
        digitalWrite(pinLed_Yellow, !digitalRead(pinLed_Yellow));
        break;
      case 3877175040:
        digitalWrite(pinLed_Green, !digitalRead(pinLed_Green));
        break;
      case 2707357440:
        digitalWrite(pinLed_Red, !digitalRead(pinLed_Red));
        break;
      case 4144561920:
        digitalWrite(pinLEDRGB_Blue, !digitalRead(pinLEDRGB_Blue));
        digitalWrite(pinLEDRGB_Green, LOW);
        digitalWrite(pinLEDRGB_Red, LOW);
        break;
      case 3810328320:
        digitalWrite(pinLEDRGB_Green, !digitalRead(pinLEDRGB_Green));
        digitalWrite(pinLEDRGB_Blue, LOW);
        digitalWrite(pinLEDRGB_Red, LOW);
        break;
      case 2774204160:
        digitalWrite(pinLEDRGB_Red, !digitalRead(pinLEDRGB_Red));
        digitalWrite(pinLEDRGB_Green, LOW);
        digitalWrite(pinLEDRGB_Blue, LOW);
        break;
      case 4161273600:
        servoMotor.write(grauServo <= 180 ? grauServo += 60 : grauServo = 0);
        break;
      case 4127850240:
        servoMotor.write(grauServo >= 0 ? grauServo -= 60 : grauServo = 180);
        break;
      case 3125149440:
        digitalWrite(pinLEDRGB_Green, LOW);
        digitalWrite(pinLEDRGB_Blue, LOW);
        digitalWrite(pinLEDRGB_Red, LOW);
        digitalWrite(pinLed_Green, LOW);
        digitalWrite(pinLed_Red, LOW);
        digitalWrite(pinLed_Yellow, LOW);
    }
  }
}