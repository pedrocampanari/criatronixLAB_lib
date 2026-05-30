#include "clab.h"
#include <Arduino.h>

Buzzer::Buzzer(int pin){
  this->pin = pin;
}
Buzzer::Buzzer(){
}

void Buzzer::begin(){
  pinMode(this->pin, OUTPUT);
}
void Buzzer::on(){
  digitalWrite(this->pin, HIGH);
}
void Buzzer::off(){
  digitalWrite(this->pin, LOW);
}
void Buzzer::beep(int time){
  digitalWrite(this->pin, HIGH);
  delay(time);
  digitalWrite(this->pin, LOW);
}

Led::Led(int pin) {
    this->pin = pin;
}

Led::Led() {
}

void Led::begin(){
  pinMode(this->pin, OUTPUT);
}

void Led::on(){
  digitalWrite(this->pin, HIGH);
}

void Led::off(){
  digitalWrite(this->pin, LOW);
}


Button::Button(int pin){
    this->pin = pin;
}

Button::Button(){
}

void Button::begin(){
    pinMode(this->pin, INPUT);
}

bool Button::read() {
    bool value = digitalRead(this->pin);
    return value;
}


RGB_Led::RGB_Led(int r_pin, int g_pin, int b_pin ) {
  this->r_pin = r_pin;
  this->r_pin = g_pin;
  this->r_pin = b_pin;
}

void RGB_Led::begin() {
    pinMode(this->r_pin, OUTPUT);
    pinMode(this->g_pin, OUTPUT);
    pinMode(this->b_pin, OUTPUT);
}

void RGB_Led::on(int r, int g, int b){
  analogWrite(this->r_pin, r);
  analogWrite(this->g_pin, g);
  analogWrite(this->b_pin, b);
}

void RGB_Led::on(){
  
}

void RGB_Led::off(){
  analogWrite(this->r_pin, 0);
  analogWrite(this->g_pin, 0);
  analogWrite(this->b_pin, 0);
}


LDR::LDR(int pin){
  this->pin = pin;
}
LDR::LDR(){
}
void LDR::begin(){
  pinMode(this->pin, INPUT);
}
int LDR::read(){
  return analogRead(this->pin);
}

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
}
Potentiometer::Potentiometer(){
}
void Potentiometer::begin(){
  pinMode(this->pin, INPUT);
}
int Potentiometer::read(){
  return analogRead(this->pin);
}



Ultrasonic::Ultrasonic(int trigger, int echo) {
    this->trigger = trigger;
    this->echo = echo;

}

Ultrasonic::Ultrasonic(){
}

void Ultrasonic::begin() {
}

void CLAB::begin() {
  this->btn1.begin();
  this->btn2.begin();
  this->buzzer.begin();
  this->rgb.begin();
  this->r_led.begin();
  this->g_led.begin();
  this->y_led.begin();
  this->pot.begin();
  this->ldr.begin();
  
}


