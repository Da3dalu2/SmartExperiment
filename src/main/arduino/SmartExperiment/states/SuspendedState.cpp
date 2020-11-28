#include "SuspendedState.h"

SuspendedState::SuspendedState(UpdateStatusTask& task) {
    this->task = task;
    this->motionDetected = false;
}

void SuspendedState::execute() {
    motionDetected = task.isMotionDetected();
    if ( motionDetected ) {
        task.updateState(*new ReadyState(task));
    }
}
