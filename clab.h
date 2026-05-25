#ifndef CLAB_H
#define CLAB_H

#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11 
#define D12 12
#define D13 13


class Led {
    private: 
        int pin;
    
    public: 
        Led(int pin);
        Led();

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

#endif