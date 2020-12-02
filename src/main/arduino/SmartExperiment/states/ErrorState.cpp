#include "ErrorState.h"

ErrorState::ErrorState(UpdateStatusTask& task, String errorDescription) {
    this->task = task;
    this->errorDescription = errorDescription;
    this->timeElapsed = 0;
}

void ErrorState::execute() {
    if ( timeElapsed < errorTime && timeElapsed == 0) {
        log(errorDescription);
        timeElapsed++;
    } else if ( timeElapsed < errorTime ) {
        timeElapsed++;
    } else if ( timeElapsed >= errorTime ) {
        timeElapsed = 0;
        task.updateState(*new SuspendedState(task));
    }
}