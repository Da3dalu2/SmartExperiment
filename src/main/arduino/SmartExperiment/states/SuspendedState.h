#ifndef __SUSPENDED_STATE_H_
#define __SUSPENDED_STATE_H_

#include "State.h"
#include "ReadyState.h"
#include "UpdateStatusTask.h"

class SuspendedState: public State {

public:
    SuspendedState(UpdateStatusTask& task);
    void execute();
    
private:
    UpdateStatusTask task;
    bool motionDetected;
};

#endif // __SUSPENDED_STATE_H_
