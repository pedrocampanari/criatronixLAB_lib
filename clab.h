#ifndef CLAB_H
#define CLAB_H

#include <Servo.h>
#include <dht.h>

#define BUZZER 2
#define SERVO 3
#define B_RGB_LED 4
#define BTN1 5
#define BTN2 6
#define G_RGB_LED 7
#define R_RGB_LED 8
#define ULTRA_TRIGGER 9
#define ULTRA_ECHO 10
#define DHT 11
#define IR 12
#define POTENTIOMETER A0;
#define LDR A1;
#define HL A2; 
#define RED_LED A3;
#define GREEN_LED A4;
#define YELLOW_LED A5;
#define DISPLAY_I2C_SDA A4;
#define DISPLAY_I2C_SCL A5;



class Led {
    private: 
        int pin;
    
    public: 
        Led(int pin);
        Led();

        void begin();
        void on();
        void off();

};

class RGB_Led {
    private: 
        int r_pin;
        int g_pin;
        int b_pin;
    
    public: 
        Led(int r_pin, int g_pin, int b_pin);
        Led();

        void begin();
        void on(int r, int g, int b);
        void on();
        void off();

};

class Ultrasonic{
    private: 
        int trigger;
        int echo;
    
    public:  
        Ultrasonic(int trigger, int echo);
        Ultrasonic();
        void begin();

};

class Button{
    private: 
        int pin;
    public:
        Button(int pin);
        Button();
        void begin();
        void read();
};

class CLAB {
    private: 
        Button btn1;
        Button btn2;
        RGB_Led rgb;
        Led r_led;
        Led g_led;
        Led b_led;

        Servo servo;
        dht DHT;

    public: 
    //Erro nas pinagens
        CLAB() : btn1(BTN1), btn2(BTN2), rgb(RED_LED, GREEN_LED, BLUE_LED) 

};

#endif