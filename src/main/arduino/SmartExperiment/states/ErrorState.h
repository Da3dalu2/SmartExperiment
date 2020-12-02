#ifndef __ERROR_STATE_H_
#define __ERROR_STATE_H_

#include "State.h"
#include "SuspendedState.h"
#include "UpdateStatusTask.h"
#include "Logger.h"

class ErrorState final: public State {

public:
    ErrorState(UpdateStatusTask& task, String errorDescription);
    void execute();

private:
    const uint16_t errorTime = 2; // s
    uint16_t timeElapsed;
    String errorDescription;
    UpdateStatusTask task;
};

#endif // __ERROR_STATE_H_
