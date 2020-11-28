#include "ReadyState.h"

/**
 * No reset method needed. It executes only one time.
 */ 
ReadyState::ReadyState(UpdateStatusTask& task) {
    this->task = task;
    this->timeElapsed = 0;
    this->startButtonPressed = false;
    this->objectDetected = false;
}

void ReadyState::execute() {
    objectDetected = task.isObjectDetected();
    startButtonPressed = task.isStartButtonPressed();

    if ( !startButtonPressed && timeElapsed > SLEEP_TIME ) {
        task.updateState(*new SuspendedState(task));
    }  else if ( !startButtonPressed && timeElapsed <= SLEEP_TIME ) {
        timeElapsed++;
    }  else if ( startButtonPressed && objectDetected ) {  
        task.updateState(*new RunningState(task));
    }  else if ( startButtonPressed && !objectDetected ) {
        task.updateState(*new SuspendedState(task));
    }
}