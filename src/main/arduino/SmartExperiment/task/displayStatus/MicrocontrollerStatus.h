#ifndef __MICROCONTROLLER_STATUS_H_
#define __MICROCONTROLLER_STATUS_H_

#include "Led.h"
#include "State.h"
#include "ErrorState.h"

class MicrocontrollerStatus {

public:
    MicrocontrollerStatus(uint8_t startLedPin, uint8_t endLedPin);
    void init();
    void displayStatus(EnumState currentState);

private:
    void blink(Led* led);
    bool isHigh;
    uint8_t startLedPin;
    uint8_t endLedPin;
    Led* startLed;
    Led* endLed;
};

#endif // __MICROCONTROLLER_STATUS_H_