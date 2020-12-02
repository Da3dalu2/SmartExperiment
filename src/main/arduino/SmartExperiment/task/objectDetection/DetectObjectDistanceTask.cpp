#include "DetectObjectDistanceTask.h"

void DetectObjectDistanceTask::tick() {
    if ( currentState == EnumState::Running )
        taskDirector->notifyObjectDistanceChange(sonar->getDistance(), sonar->getTime());
}

void DetectObjectDistanceTask::update(UpdateStatusTask& subject) {
    this->currentState = subject.getCurrentState();
}

void DetectObjectDistanceTask::updateSamplingFrequency(
    uint8_t samplingFrequency) {
    if ( currentState == EnumState::Ready )
        this->period = samplingFrequency;
}