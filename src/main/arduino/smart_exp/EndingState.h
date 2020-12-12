#ifndef __ENDING_STATE_H_
#define __ENDING_STATE_H_

#include "State.h"
#include "ReadyState.h"
#include "UpdateStatusTask.h"

class UpdateStatusTask;

class EndingState: public State {

public:
    EndingState(UpdateStatusTask* task);
    void execute();
    EnumState getState();

private:
    UpdateStatusTask* task;
    bool endConfirmationReceived;
    bool exitConfirmed;
};

#endif // __ENDING_STATE_H_

