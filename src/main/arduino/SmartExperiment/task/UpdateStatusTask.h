#ifndef __UPDATE_STATUS_TASK_H_
#define __UPDATE_STATUS_TASK_H_

#include "SmartExperiment.h"
#include "State.h"
#include "ReadyState.h"
#include "Task.h"
#include "Subject.h"
#include "TaskDirector.h"
#include "Communicator.h"
#include "EnumState.h"

class UpdateStatusTask: public Task, public Subject, public Communicator {

public:
    UpdateStatusTask();
    void init(uint16_t period);
    void tick();
    void setMotionDetected(bool motionDetected);
    void setObjectDetected(bool objectDetected);
    void setStartButtonPressed(bool startButtonPressed);
    void setEndButtonPressed(bool endButtonPressed);
    void setEndConfirmationReceived(bool endConfirmationReceived);
    bool isMotionDetected();
    bool isObjectDetected();
    bool isStartButtonPressed();
    bool isEndButtonPressed();
    bool isEndConfirmationReceived();
    EnumState getCurrentState();
    void updateState(State& nextState);

private:
    State* currentState;
    bool startButtonPressed;
    bool objectDetected;
    bool endButtonPressed;
    bool motionDetected;
    bool endConfirmationReceived;
};

#endif // __UPDATE_STATUS_TASK_H_