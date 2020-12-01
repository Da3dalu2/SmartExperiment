#include "DetectObjectDistanceTask.h"

void DetectObjectDistanceTask::tick() {
    if ( typeid(currentState) == typeid(RunningState) )
        taskDirector.notifyObjectDistanceChange(*this, sonar->computeDistance());
}

void DetectObjectDistanceTask::update(UpdateStatusTask& subject) {
    this->currentState = subject.getCurrentState();
}