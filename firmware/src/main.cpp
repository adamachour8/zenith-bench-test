#include <Arduino.h>
#include "IMUReader.h"

#define PIN_IMU_CS 37

IMUReader imu(PIN_IMU_CS);

void setup() {
    Serial.begin(115200);

    imu.begin();

    Serial.println("Bench test ready.");
}

void loop() {
    imu.update();

    Serial.print("{");
    Serial.print("\"accel_x\":"); Serial.print(imu.getAccelX());
    Serial.print(",\"accel_y\":"); Serial.print(imu.getAccelY());
    Serial.print(",\"accel_z\":"); Serial.print(imu.getAccelZ());
    Serial.println("}");

    delay(50);
}