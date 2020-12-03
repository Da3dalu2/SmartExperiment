#include "SchedulerManager.h"

SchedulerManager::SchedulerManager(Scheduler* sched) {
    this->sched = sched;
    this->currentState = EnumState::Ready;
    this->readyStateTaskList = new LinkedList<Task*>();
    this->runningStateTaskList = new LinkedList<Task*>();
    this->suspendedStateTask = new DetectMotionTask();
}

SchedulerManager::init() {
    UpdateStatusTask updateStatusTask = new UpdateStatusTask();
    DisplayStatusTask displayStatusTask = new DisplayStatusTask();

    readyStateTaskList.add(updateStatusTask);
    readyStateTaskList.add(displayStatusTask);
    readyStateTaskList.add()
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
            sched->addTask(new DisplayStatusTask());
            sched->addTask(new
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