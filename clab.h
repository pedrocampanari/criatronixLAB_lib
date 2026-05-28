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
#define POTENTIOMETER A0
#define LDR A1
#define HL A2
#define RED_LED A3
#define GREEN_LED A4
#define YELLOW_LED A5
#define DISPLAY_I2C_SDA A4
#define DISPLAY_I2C_SCL A5



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
        RGB_Led(int r_pin, int g_pin, int b_pin);
        RGB_Led();

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
        bool read();
};

class CLAB {
    private: 
        Button btn1;
        Button btn2;
        RGB_Led rgb;
        Led r_led;
        Led g_led;
        Led y_led;

        Servo servo;
        dht dht_sensor;

    public: 
    //Erro nas pinagens
        CLAB() : 
          btn1(BTN1), 
          btn2(BTN2), 
          rgb(R_RGB_LED, G_RGB_LED, B_RGB_LED), 
          r_led(RED_LED), g_led(GREEN_LED), 
          y_led(YELLOW_LED){}

};

#endif