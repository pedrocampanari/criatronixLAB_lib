#include <NewPing.h>

#define pinTrig 9
#define pinEcho 10

#define ledVermelho A4
#define ledVerde A3
#define ledAmarelo A5
#define buzzer 2

NewPing Ultrassonic = NewPing(pinTrig, pinEcho, 35);

void setup() {
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  int distCM = Ultrassonic.ping_cm();

  Serial.print("Distancia em cm: ");
  Serial.println(distCM);

  if (distCM <= 5 && distCM != 0) {
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  } else if (distCM <= 10 && distCM != 0) {
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else if (distCM <= 15 && distCM != 0) {
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(250);
}