#ifndef __ERROR_STATE_H_
#define __ERROR_STATE_H_

#include "State.h"
#include "SuspendedState.h"
#include "Logger.h"
#include "UpdateStatusTask.h"

class UpdateStatusTask;

class ErrorState: public State {

public:
    ErrorState(UpdateStatusTask* task, String errorDescription);
    void execute();
    EnumState getState();

private:
    const uint16_t errorTime = 2; // s
    uint16_t timeElapsed;
    String errorDescription;
    UpdateStatusTask* task;
};

#endif // __ERROR_STATE_H_
