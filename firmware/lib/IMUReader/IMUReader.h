#pragma once
#include <ICM42688.h>
#include <SPI.h>

class IMUReader {
public:
    IMUReader(uint8_t csPin);
    bool begin();
    void update();
    float getAccelX();
    float getAccelY();
    float getAccelZ();

private:
    ICM42688 _imu;
    float _ax, _ay, _az;
};