#ifndef __ENDING_STATE_H_
#define __ENDING_STATE_H_

#include "State.h"
#include "ReadyState.h"
#include "UpdateStatusTask.h"

class EndingState: public State {

public:
    EndingState(UpdateStatusTask& task);
    void execute();

private:
    UpdateStatusTask task;
    bool endConfirmationReceived;
};

#endif // __ENDING_STATE_H_

