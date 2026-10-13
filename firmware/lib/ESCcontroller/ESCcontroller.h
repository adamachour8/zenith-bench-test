#pragma once
#include <Servo.h>

class ESCcontroller {
public:
    ESCcontroller(uint8_t escPin);
    int arm();
    int init();
    void setPWM(uint16_t pwm);
    uint16_t getPWM() { return _pwm; };

private:
    Servo _esc;
    uint8_t _escPin; 
    uint16_t _pwm;
    bool _armed;
};