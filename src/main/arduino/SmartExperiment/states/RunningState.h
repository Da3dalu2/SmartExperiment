#ifndef __RUNNING_STATE_H_
#define __RUNNING_STATE_H_

#include "State.h"
#include "EndingState.h"
#include "UpdateStatusTask.h"

#define MAX_TIME 20

class RunningState final: public State {

public:
    RunningState(UpdateStatusTask& task);
    void execute();

private:
    UpdateStatusTask task;
    uint16_t timeElapsed;
    bool endButtonPressed;
};

#endif // __RUNNING_STATE_H_
