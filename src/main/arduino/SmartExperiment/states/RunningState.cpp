#include "RunningState.h"

/**
 * No reset method needed. It executes only one time.
 */ 
RunningState::RunningState(UpdateStatusTask& task) {
    this->task = task;
    this->timeElapsed = 0;
    this->endButtonPressed = false;
}

void RunningState::execute() {
    if ( endButtonPressed || timeElapsed > maxTime ) {
        task.updateState(*new EndingState(task));
    } else if ( !endButtonPressed && timeElapsed <= maxTime ) {
        timeElapsed++;
    }
}
