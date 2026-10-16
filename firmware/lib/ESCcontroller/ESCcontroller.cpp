#include "ESCcontroller.h"

ESCcontroller::ESCcontroller(uint8_t escPin)
    : _escPin(escPin), _pwm(0), _armed(false) {}

int ESCcontroller::init() {
    _esc.attach(_escPin);
    return 1;
}

int ESCcontroller::arm() {
    if (_armed) return 0;

    _esc.writeMicroseconds(PWM_ARM);
    delay(2000); // TODO: replace with non-blocking arm sequence
    _armed = true;
    return 1;
}

void ESCcontroller::disarm() {
    _esc.writeMicroseconds(PWM_ARM);
    _pwm = 0;
    _armed = false;
}

void ESCcontroller::setPWM(uint16_t pwm) {
    if (!_armed) return;

    // Clamp to safe range
    if (pwm < PWM_MIN) pwm = PWM_MIN;
    if (pwm > PWM_MAX) pwm = PWM_MAX;

    _pwm = pwm;
    _esc.writeMicroseconds(_pwm);
}
