#define botao1 5
#define botao2 6

#define pinLed_Green A3
#define pinLed_Red A4
#define pinLed_Yellow A5
#define pinLEDRGB_Blue 4
#define pinLEDRGB_Green 7
#define pinLEDRGB_Red 8

int estadoBotao1Anterior = HIGH;
int estadoBotao2Anterior = HIGH;
int contador1 = 0;
int contador2 = 0;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  pinMode(pinLed_Green, OUTPUT);
  pinMode(pinLed_Red, OUTPUT);
  pinMode(pinLed_Yellow, OUTPUT);
  pinMode(pinLEDRGB_Green, OUTPUT);
  pinMode(pinLEDRGB_Red, OUTPUT);
  pinMode(pinLEDRGB_Blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int estadoBotao1 = digitalRead(botao1);
  int estadoBotao2 = digitalRead(botao2);

  // Detecta clique (borda de descida)
  if (estadoBotao1Anterior == HIGH && estadoBotao1 == LOW) {
    contador1++;
    if (contador1 > 3) contador1 = 0;
    delay(200);
  }
  estadoBotao1Anterior = estadoBotao1;

  if (estadoBotao2Anterior == HIGH && estadoBotao2 == LOW) {
    contador2++;
    if (contador2 > 3) contador2 = 0;
    delay(200);
  }
  estadoBotao2Anterior = estadoBotao1;

  if (contador1 == 0) {
    digitalWrite(pinLed_Green, LOW);
    digitalWrite(pinLed_Red, LOW);
    digitalWrite(pinLed_Yellow, LOW);
  }
  if (contador1 == 1) digitalWrite(pinLed_Green, HIGH);
  if (contador1 == 2) digitalWrite(pinLed_Red, HIGH);
  if (contador1 == 3) digitalWrite(pinLed_Yellow, HIGH);

  switch (contador2) {
    case 0:
      digitalWrite(pinLEDRGB_Green, LOW);
      digitalWrite(pinLEDRGB_Red, LOW);
      digitalWrite(pinLEDRGB_Blue, LOW);
      break;
    case 1:
      digitalWrite(pinLEDRGB_Green, HIGH);
      digitalWrite(pinLEDRGB_Red, LOW);
      digitalWrite(pinLEDRGB_Blue, LOW);
      break;
    case 2:
      digitalWrite(pinLEDRGB_Green, LOW);
      digitalWrite(pinLEDRGB_Red, HIGH);
      digitalWrite(pinLEDRGB_Blue, LOW);
      break;
    case 3:
      digitalWrite(pinLEDRGB_Green, LOW);
      digitalWrite(pinLEDRGB_Red, LOW);
      digitalWrite(pinLEDRGB_Blue, HIGH);
  }
}