#define LDR A1
#define pinLed_Green A3
#define pinLed_Red A4
#define pinLed_Yellow A5

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR, INPUT_PULLUP);
  pinMode(pinLed_Green, OUTPUT);
  pinMode(pinLed_Red, OUTPUT);
  pinMode(pinLed_Yellow, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  int valorLDR = analogRead(LDR);
  Serial.println(valorLDR);

  if (valorLDR >= 500) {
    digitalWrite(pinLed_Green, HIGH);
    digitalWrite(pinLed_Red, HIGH);
    digitalWrite(pinLed_Yellow, HIGH);
  } else {
    digitalWrite(pinLed_Green, LOW);
    digitalWrite(pinLed_Red, LOW);
    digitalWrite(pinLed_Yellow, LOW);
  }
}
