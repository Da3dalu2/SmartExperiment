#include "RunningState.h"

RunningState::RunningState(UpdateStatusTask* task) {
    this->task = task;
    this->timeElapsed = 0;
    this->endButtonPressed = false;
}

void RunningState::execute() {
    /*if ( endButtonPressed || timeElapsed > maxTime ) {
        task.updateState(*new EndingState(task));
    } else if ( !endButtonPressed && timeElapsed <= maxTime ) {
        timeElapsed++;
    }*/
    task->updateState(new ErrorState(task, "no object detected"));
    logger.log("resolving Running state");
}

EnumState RunningState::getState() {
    return EnumState::Running;
}