#include "clab.h"


Led::Led(int pin) {
    this->pin = pin;
}

Led::Led() {
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



Ultrasonic::Ultrasonic(int trigger, int echo) {
    this->trigger = trigger;
    this->echo = echo;

}

Ultrasonic::Ultrasonic(){
}

void Ultrasonic::begin() {
}


