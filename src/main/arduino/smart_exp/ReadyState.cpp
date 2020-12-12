#include "ReadyState.h"

/**
 * No reset method needed. It executes only one time.
 */ 
ReadyState::ReadyState(UpdateStatusTask* task) {
    this->task = task;
    this->timeElapsed = 0;
    this->startButtonPressed = false;
    this->objectDetected = false;
}

void ReadyState::execute() {
    objectDetected = task->isObjectDetected();
    startButtonPressed = task->isStartButtonPressed();

    if ( !startButtonPressed && timeElapsed > sleepTime ) {
        task->updateState(new SuspendedState(task));
        logger.log("Too much time elapsed!");
    }  else if ( !startButtonPressed && timeElapsed <= sleepTime ) {
        timeElapsed++;
        logger.log("Adding up to the count...");
    }  else if ( startButtonPressed && objectDetected ) {  
        task->updateState(new RunningState(task));
    }  else if ( startButtonPressed && !objectDetected ) {
        task->updateState(new ErrorState(task, 
            "no objects detected, the experiment cannot begin"));
        logger.log("Where's Waldo?");
    }
    //task->updateState(new RunningState(task));
    //logger.log("resolving Ready state");
}

EnumState ReadyState::getState() {
    return EnumState::Ready;
}