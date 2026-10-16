#pragma once
#include <Servo.h>

class ESCcontroller {
public:
    ESCcontroller(uint8_t escPin);

    int init();
    int arm();
    void disarm();
    void setPWM(uint16_t pwm);
    uint16_t getPWM() const { return _pwm; }
    bool isArmed() const { return _armed; }

private:
    static constexpr uint16_t PWM_MIN = 1000;
    static constexpr uint16_t PWM_MAX = 2000;
    static constexpr uint16_t PWM_ARM = 1000;

    Servo _esc;
    uint8_t _escPin;
    uint16_t _pwm;
    bool _armed;
};