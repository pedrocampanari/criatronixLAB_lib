#include <NewPing.h>
#include <Servo.h>

#define pinTrig 9
#define pinEcho 10

#define ledVermelho A4
#define ledAmarelo A5
#define buzzer 2

NewPing Ultrassonic = NewPing(pinTrig, pinEcho, 11);
Servo cancela;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(buzzer, OUTPUT);
  cancela.attach(3);
  cancela.write(180);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int distCM = Ultrassonic.ping_cm();
  Serial.print("Distancia em cm: ");
  Serial.println(distCM);
  if (distCM <= 5 && distCM != 0) {
    cancela.write(90);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    delay(800);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    delay(800);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    delay(800);
    digitalWrite(ledAmarelo, LOW);
    cancela.write(180);
  }
  delay(100);
}
