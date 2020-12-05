#include "EndingState.h"

EndingState::EndingState(UpdateStatusTask& task) {
    this->task = task;
    this->endConfirmationReceived = false;
}

void EndingState::execute() {
    endConfirmationReceived = task.isEndConfirmationReceived();
    if ( endConfirmationReceived ) {
        if ( confirmed ) {
            task.updateState(*new ReadyState(task));
        } else {
            task.updateState(*new RunningState(task));
        }
    }
}

