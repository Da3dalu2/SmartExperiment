#ifndef __UPDATE_STATUS_TASK_H_
#define __UPDATE_STATUS_TASK_H_

#include "SmartExperiment.h"
#include "Task.h"
#include "EnumState.h"
#include "State.h"
#include "ReadyState.h"
#include "StateSubject.h"
#include "TaskDirector.h"
#include "Communicator.h"

class TaskDirector;

class UpdateStatusTask: public Task, public StateSubject, public Communicator {

public:
    UpdateStatusTask();
    void init(uint32_t period);
    void tick();
    void setMotionDetected(bool motionDetected);
    void setObjectDetected(bool objectDetected);
    void setStartButtonPressed(bool startButtonPressed);
    void setEndButtonPressed(bool endButtonPressed);
    void setEndConfirmationReceived(bool endConfirmationReceived, bool exitConfirmed);
    bool isMotionDetected();
    bool isObjectDetected();
    bool isStartButtonPressed();
    bool isEndButtonPressed();
    bool isEndConfirmationReceived();
    bool isExitConfirmed();
    EnumState getCurrentState();
    void updateState(State* nextState);
    void notifyObservers();

private:
    State* currentState;
    bool startButtonPressed;
    bool objectDetected;
    bool endButtonPressed;
    bool motionDetected;
    bool endConfirmationReceived;
    bool exitConfirmed;
};

#endif // __UPDATE_STATUS_TASK_H_