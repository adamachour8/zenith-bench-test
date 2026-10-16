#include "ESCcontroller.h"

ESCcontroller::ESCcontroller(uint8_t escPin)
    : _escPin(escPin), _pwm(0), _armed(false) {}

int ESCcontroller::arm() {
    if (_armed) {
        return 0; // Already armed
    }
    _esc.attach(_escPin);
    _esc.writeMicroseconds(1000); // Send minimum PWM signal to arm ESC
    delay(2000); // Wait for ESC to arm
    _armed = true;
    return 1; // Successfully armed
}     

void ESCcontroller::setPWM(uint16_t pwm) {
    if (_armed) {
        _pwm = pwm;
        _esc.writeMicroseconds(_pwm);
    }
}

