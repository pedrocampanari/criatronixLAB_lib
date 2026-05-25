#define botao1 5
#define botao2 6
#define buzzer 2

void setup() {
  // put your setup code here, to run once:
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool estadoBotao1 = digitalRead(botao1);
  bool estadoBotao2 = digitalRead(botao2);

  if (estadoBotao1 == false) {
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
  if (estadoBotao2 == false) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  digitalWrite(buzzer, LOW);
}
