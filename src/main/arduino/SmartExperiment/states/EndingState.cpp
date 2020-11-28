#include "EndingState.h"

EndingState::EndingState(UpdateStatusTask& task) {
    this->task = task;
    this->endConfirmationReceived = false;
}

void EndingState::execute() {
    endConfirmationReceived = task.isEndConfirmationReceived();
    if ( endConfirmationReceived ) {
        task.updateState(*new ReadyState(task));
    }
}

