#include "SchedulerManager.h"

SchedulerManager::SchedulerManager(Scheduler* sched) {
    this->sched = sched;
    this->currentState = EnumState::Ready;
}

/**
 * TODO: complete this method.
 * The scheduler must init tasks only the first time.
 * Some tasks should subscribe to an observer or mediator.
 */ 
void SchedulerManager::checkScheduling() {
    switch(currentState) {
        case EnumState::Ready:
            sched->addTask();
            break;
        case EnumState::Running:
            sched->addTask();
            break;
        case EnumState::Error:
            break;
        case EnumState::Ending:
            sched->addTask();
            break;
        case EnumState::Suspended:
            sched->addTask();
            break;
    }
}

void SchedulerManager::update(UpdateStatusTask& task) {
    currentState = task.getCurrentState();
}