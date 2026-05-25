#include "clab.h"
#include <iostream>

using namespace std;

Led::Led(int pin) {
    this->pin = pin;
}

Led::Led() {
}

Ultrasonic::Ultrasonic(int trigger, int echo) {
    this->trigger = trigger;
    this->echo = echo;

}

Ultrasonic::Ultrasonic(){
}

void Ultrasonic::begin() {
    cout << "OK" << endl;
}
