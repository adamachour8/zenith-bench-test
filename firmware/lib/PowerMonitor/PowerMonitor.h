#pragma once
#include <FlexCAN_T4.h>

class PowerMonitor {
public:
    PowerMonitor();

    int init();
    void update();  // call in loop to process CAN frames

    float getVoltage() const { return _voltage; }
    float getCurrent() const { return _current; }
    float getPower() const { return _voltage * _current; }
    bool isConnected() const { return _connected; }

private:
    void _parseDroneCANFrame(const CAN_message_t &msg);

    static constexpr uint32_t CAN_BAUD = 1000000;  // DroneCAN default 1Mbps
    static constexpr uint32_t TIMEOUT_MS = 1000;

    float _voltage;
    float _current;
    bool _connected;
    uint32_t _lastUpdateMs;
};