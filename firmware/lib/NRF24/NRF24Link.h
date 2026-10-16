#pragma once
#include <SPI.h>
#include <RF24.h>

enum class SystemState : uint8_t {
    IDLE,
    ARMED,
    RUNNING,
    ESTOP
};

struct GroundCommand {
    SystemState state;
    uint16_t throttle;  // potentiometer value 0-1023
};

class NRF24Link {
public:
    NRF24Link(uint8_t cePin, uint8_t csPin);

    int init();
    bool update();  // returns true if new command received
    
    GroundCommand getLastCommand() const { return _lastCmd; }
    SystemState getState() const { return _lastCmd.state; }
    bool isConnected() const { return _connected; }

private:
    static constexpr uint32_t TIMEOUT_MS = 500;
    static constexpr uint8_t PIPE_ADDR[6] = "ZNTRF";  // TODO: agree with ground station

    RF24 _radio;
    GroundCommand _lastCmd;
    bool _connected;
    uint32_t _lastRxMs;
};