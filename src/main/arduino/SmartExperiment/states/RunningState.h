#ifndef __RUNNING_STATE_H_
#define __RUNNING_STATE_H_

#include "State.h"
#include "EndingState.h"
#include "UpdateStatusTask.h"

class RunningState final: public State {

public:
    RunningState(UpdateStatusTask& task);
    void execute();

private:
    const uint8_t maxTime = 20; // s
    UpdateStatusTask task;
    uint16_t timeElapsed;
    bool endButtonPressed;
};

#endif // __RUNNING_STATE_H_
