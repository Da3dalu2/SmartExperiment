#ifndef __MICROCONTROLLER_STATUS_H_
#define __MICROCONTROLLER_STATUS_H_

#include "BlinkLed.h"
#include "State.h"
#include "ErrorState.h"

class MicrocontrollerStatus {

public:
    MicrocontrollerStatus();
    void init();
    void displayStatus(EnumState currentState);
};

#endif // __MICROCONTROLLER_STATUS_H_