#include "EndingState.h"

EndingState::EndingState(UpdateStatusTask* task) {
    this->task = task;
    this->endConfirmationReceived = false;
    this->exitConfirmed = false;
}

void EndingState::execute() {
    endConfirmationReceived = task->isEndConfirmationReceived();
    exitConfirmed = task->isExitConfirmed();
    if ( endConfirmationReceived ) {
        if ( exitConfirmed ) {
            task->updateState(new ReadyState(task));
        } else {
            task->updateState(new RunningState(task));
        }
        logger.log("resolving Ending state");
    }
    task->updateState(new ReadyState(task));
    
}

EnumState EndingState::getState() {
    return EnumState::Ending;
}