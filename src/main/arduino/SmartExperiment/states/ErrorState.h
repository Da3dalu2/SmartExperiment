#ifndef __ERROR_STATE_H_
#define __ERROR_STATE_H_

#include "State.h"
#include "SuspendedState.h"
#include "UpdateStatusTask.h"
#include "Logger.h"
#include "BlinkTask.h"

class ErrorState final: public State {

public:
    ErrorState(UpdateStatusTask& task, String errorDescription);
    void execute();

private:
    const uint16_t errorTime = 20;
    const uint8_t errorLedPin = 2;
    uint16_t timeElapsed;
    String errorDescription;
    BlinkTask* errorLedBlinking;
    UpdateStatusTask task;
};

#endif // __ERROR_STATE_H_
