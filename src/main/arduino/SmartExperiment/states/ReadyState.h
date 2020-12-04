#ifndef __READY_STATE_H_
#define __READY_STATE_H_

#include "State.h"
#include "SuspendedState.h"
#include "RunningState.h"
#include "ErrorState.h"
#include "UpdateStatusTask.h"

class ReadyState final: public State {

public:
    ReadyState(UpdateStatusTask& task);
    void execute();
    EnumState getState();

private:
    const uint8_t sleepTime = 20; // s 
    UpdateStatusTask task;
    uint16_t timeElapsed;
    bool startButtonPressed;
    bool objectDetected;
};

#endif // __READY_STATE_H_
