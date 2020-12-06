#ifndef __SUSPENDED_STATE_H_
#define __SUSPENDED_STATE_H_

#include "State.h"
#include "ReadyState.h"
#include "UpdateStatusTask.h"

class UpdateStatusTask;

class SuspendedState: public State {

public:
    SuspendedState(UpdateStatusTask* task);
    void execute();
    EnumState getState();
    
private:
    UpdateStatusTask* task;
    bool motionDetected;
};

#endif // __SUSPENDED_STATE_H_
