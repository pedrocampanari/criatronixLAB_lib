#include <Servo.h>

#define pinPot A0
Servo motorServo;

void setup() {
  // put your setup code here, to run once:
  motorServo.attach(3);
  pinMode(pinPot, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valuePot = analogRead(pinPot);
  int grauServo = map(valuePot, 13, 1023, 0, 180);

  motorServo.write(grauServo);
  Serial.println(valuePot);
  
}
