#include <Arduino.h>
#include "IMUReader.h"
#include "ESCcontroller.h"
#include "PowerMonitor.h"
#include "NRF24Link.h"

#define PIN_IMU_CS   37
#define PIN_ESC      2    // TODO: confirm
#define PIN_NRF_CE   3    // TODO: confirm
#define PIN_NRF_CS   4    // TODO: confirm

IMUReader imu(PIN_IMU_CS);
ESCcontroller esc(PIN_ESC);
PowerMonitor pm;
NRF24Link rf(PIN_NRF_CE, PIN_NRF_CS);

void setup() {
    Serial.begin(115200);

    imu.begin();
    esc.init();
    pm.init();
    rf.init();

    Serial.println("Bench test ready.");
}

void loop() {
    imu.update();
    pm.update();

    // Check RF commands
    if (rf.update()) {
        GroundCommand cmd = rf.getLastCommand();
        if (cmd.state == SystemState::ESTOP) {
            esc.disarm();
        }
    }

    Serial.print("{");
    Serial.print("\"accel_x\":"); Serial.print(imu.getAccelX());
    Serial.print(",\"accel_y\":"); Serial.print(imu.getAccelY());
    Serial.print(",\"accel_z\":"); Serial.print(imu.getAccelZ());
    Serial.print(",\"voltage\":"); Serial.print(pm.getVoltage());
    Serial.print(",\"current\":"); Serial.print(pm.getCurrent());
    Serial.print(",\"power\":"); Serial.print(pm.getPower());
    Serial.print(",\"pwm\":"); Serial.print(esc.getPWM());
    Serial.print(",\"armed\":"); Serial.print(esc.isArmed());
    Serial.print(",\"rf_connected\":"); Serial.print(rf.isConnected());
    Serial.print(",\"state\":"); Serial.print((uint8_t)rf.getState());
    Serial.println("}");

    delay(50);
}