#ifndef __READY_STATE_H_
#define __READY_STATE_H_

#include "State.h"
#include "SuspendedState.h"
#include "RunningState.h"
#include "ErrorState.h"
#include "UpdateStatusTask.h"

#define SLEEP_TIME 20
#define DEBOUNCE_DELAY 50

class ReadyState final: public State {

public:
    ReadyState(UpdateStatusTask& task);
    void execute();

private:
    UpdateStatusTask task;
    uint16_t timeElapsed;
    bool startButtonPressed;
    bool objectDetected;
};

#endif // __READY_STATE_H_
