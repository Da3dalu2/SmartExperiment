#ifndef __ERROR_STATE_H_
#define __ERROR_STATE_H_

#include "State.h"
#include "SuspendedState.h"
#include "UpdateStatusTask.h"
#include "Logger.h"
#include "BlinkLed.h"

class ErrorState final: public State {

public:
    ErrorState(UpdateStatusTask& task, const char* errorDescription);
    void execute();

private:
    const uint16_t errorTime = 2; // s
    const uint8_t errorLedPin = 2;
    uint16_t timeElapsed;
    const char errorDescription;
    BlinkTask* errorLedBlinking;
    UpdateStatusTask task;
};

#endif // __ERROR_STATE_H_
