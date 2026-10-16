#include "PowerMonitor.h"

// TODO: confirm CAN1 vs CAN2 with electrical team
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> canBus;

PowerMonitor::PowerMonitor()
    : _voltage(0.0f), _current(0.0f), _connected(false), _lastUpdateMs(0) {}

int PowerMonitor::init() {
    canBus.begin();
    canBus.setBaudRate(CAN_BAUD);
    return 1;
}

void PowerMonitor::update() {
    CAN_message_t msg;
    while (canBus.read(msg)) {
        _parseDroneCANFrame(msg);
        _lastUpdateMs = millis();
        _connected = true;
    }

    // Timeout detection
    if (millis() - _lastUpdateMs > TIMEOUT_MS) {
        _connected = false;
    }
}

void PowerMonitor::_parseDroneCANFrame(const CAN_message_t &msg) {
    // TODO: decode DroneCAN circuit_status message
    // PM08-CAN sends uavcan.equipment.power.CircuitStatus
    // Fields: voltage_v (float16), current_a (float16)
    // Need to extract DroneCAN transfer ID, data type ID (1091),
    // and deserialize float16 fields from payload
    (void)msg;
}