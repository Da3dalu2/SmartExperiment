#include "ErrorState.h"

ErrorState::ErrorState(UpdateStatusTask* task, String errorDescription) {
    this->task = task;
    this->errorDescription = errorDescription;
    this->timeElapsed = 0;
}

void ErrorState::execute() {
    /*if ( timeElapsed < errorTime && timeElapsed == 0) {
        logger.log(errorDescription);
        timeElapsed++;
    } else if ( timeElapsed < errorTime ) {
        timeElapsed++;
    } else if ( timeElapsed >= errorTime ) {
        timeElapsed = 0;
        task.updateState(*new SuspendedState(task));
    }*/
    task->updateState(new EndingState(task));
    //logger.log("resolving Error state");
}

EnumState ErrorState::getState() {
    return EnumState::Error;
}