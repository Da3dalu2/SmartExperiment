#ifndef __UPDATE_STATUS_TASK_H_
#define __UPDATE_STATUS_TASK_H_

#include "SmartExperiment.h"
#include "ReadyState.h"
#include "Task.h"
#include "Subject.h"
#include "TaskDirector.h"
#include <optional>

class UpdateStatusTask: public Task, public Subject {

public:
    UpdateStatusTask(); // REVIEW: why ReadyState requires a default constructor?
    UpdateStatusTask(TaskDirector& taskDirector);
    void init(uint16_t period);
    void tick();
    void setMotionDetected(bool motionDetected);
    void setObjectDetected(bool objectDetected);
    void setStartButtonPressed(bool startButtonPressed);
    void setEndButtonPressed(bool endButtonPressed);
    void setEndConfirmationReceived(bool endConfirmationReceived);
    bool UpdateStatusTask::isMotionDetected();
    bool UpdateStatusTask::isObjectDetected();
    bool isStartButtonPressed();
    bool isEndButtonPressed();
    bool isEndConfirmationReceived();
    State* getCurrentState();
    void updateState(State& nextState);

private:
    std::optional<State*> oCurrentState;
    bool startButtonPressed;
    bool objectDetected;
    bool endButtonPressed;
    bool motionDetected;
    bool endConfirmationReceived;
    TaskDirector taskDirector;

};

#endif // __UPDATE_STATUS_TASK_H_

