#include "IMUReader.h"

IMUReader::IMUReader(uint8_t csPin)
    : _imu(SPI, csPin), _ax(0), _ay(0), _az(0) {}

bool IMUReader::begin() {
    int status = _imu.begin();
    return (status > 0);
}

void IMUReader::update() {
    _imu.getAGT();
    _ax = _imu.accX();
    _ay = _imu.accY();
    _az = _imu.accZ() - 1.0; // soustraction gravité
}

float IMUReader::getAccelX() { return _ax; }
float IMUReader::getAccelY() { return _ay; }
float IMUReader::getAccelZ() { return _az; }