#include "ErrorState.h"

ErrorState::ErrorState(UpdateStatusTask& task, const char* errorDescription) {
    this->task = task;
    this->errorDescription = errorDescription;
    this->timeElapsed = 0;
    this->errorLedBlinking = new BlinkTask(errorLedPin);
}

void ErrorState::execute() {
    if ( timeElapsed < errorTime && timeElapsed == 0) {
        log(errorDescription);
        errorLedBlinking->tick();
        timeElapsed++;
    } else if ( timeElapsed < errorTime ) {
        errorLedBlinking->tick();
        timeElapsed++;
    } else if ( timeElapsed >= errorTime ) {
        timeElapsed = 0;
        task.updateState(*new SuspendedState(task));
    }
}