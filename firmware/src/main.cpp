#include <Arduino.h>
#include "IMUReader.h"

#define PIN_IMU_CS 10
#define LED_PIN 13

IMUReader imu(PIN_IMU_CS);

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    imu.begin();

    Serial.println("Bench test ready.");
    digitalWrite(LED_PIN, HIGH);
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