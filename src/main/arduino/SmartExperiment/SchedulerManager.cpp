#include "SchedulerManager.h"

SchedulerManager::SchedulerManager() {
    this->currentState = EnumState::Ready;
    this->previousState = EnumState::Ending;
    this->readyStateTaskList = *new LinkedList<Task*>();
    this->runningStateTaskList = *new LinkedList<Task*>();
}

void SchedulerManager::init(Scheduler* sched) {
    this->sched = sched;
    updateStatusTask = new UpdateStatusTask();
    MicrocontrollerStatus* microStatus = new MicrocontrollerStatus(
        startLedPin, endLedPin);
    ViewerStatus* viewerStatus = new ViewerStatus();
    displayStatusTask = new DisplayStatusTask(
        microStatus, viewerStatus);

    TaskDirector* taskDirector = new TaskDirector();

    taskDirector->registerUpdateStatusTask(updateStatusTask);
    updateStatusTask->attachMediator(taskDirector);
    updateStatusTask->attachObserver(displayStatusTask);

    sched->addTask(updateStatusTask);
    sched->addTask(displayStatusTask);

    updateStatusTask->init(4000); // milliseconds
    displayStatusTask->init(4000);

    populateLists();
}

void SchedulerManager::populateLists() {
/*
    bool op_succeded = true;
    DetectStartButtonPressTask* detectStartButtonPressTask = 
        new DetectStartButtonPressTask(startButtonPin, debounceDelay);
    DetectObjectPresenceTask* detectObjectPresenceTask =
        new DetectObjectPresenceTask(trigPin, echoPin, tempPin);
    SetSamplingFrequencyTask* setSamplingFrequencyTask =
        new SetSamplingFrequencyTask(potPin);

    op_succeded = op_succeded && readyStateTaskList.add(
        detectStartButtonPressTask);
    op_succeded = op_succeded && readyStateTaskList.add(
        detectObjectPresenceTask);
    op_succeded = op_succeded && readyStateTaskList.add(
       setSamplingFrequencyTask);

    check(op_succeded);

    updateStatusTask->attachObserver(setSamplingFrequencyTask);

    op_succeded = op_succeded && runningStateTaskList.add(
        new DetectEndButtonPressTask(endButtonPin, debounceDelay));
    op_succeded = op_succeded && runningStateTaskList.add(
        new DetectObjectDistanceTask(trigPin, echoPin, tempPin));
    op_succeded = op_succeded && runningStateTaskList.add(
        new ComputeDataTask());
    op_succeded = op_succeded && runningStateTaskList.add(new SendDataTask());
    op_succeded = op_succeded && runningStateTaskList.add(
        new DisplaySpeedTask(servoPin));

    check(op_succeded);

    suspendedStateTask = new DetectMotionTask(pirPin);*/
}

void SchedulerManager::check(bool op_succeded) {
    if ( !op_succeded ) {
        op_succeded = true;
       logger.log("Failed task insertion");
    }
}

void SchedulerManager::checkScheduling() {
    if (currentState != previousState ) {
        switch(currentState) {
            case EnumState::Ready:
                if ( sched->getTaskList().size() > 0 )
                    sched->clearTaskList();
                check(sched->addTaskList(readyStateTaskList));
                break;
            case EnumState::Running:
                sched->clearTaskList();
                check(sched->addTaskList(runningStateTaskList));
                break;
            case EnumState::Error:
                sched->clearTaskList();
                break;
            case EnumState::Ending:
                sched->clearTaskList();
                break;
            case EnumState::Suspended:
                sched->clearTaskList();
                check(sched->addTask(suspendedStateTask));
                break;
        }
        sched->addTask(updateStatusTask);
        sched->addTask(displayStatusTask);
    }
    previousState = currentState;
}

void SchedulerManager::update(EnumState state) {
    previousState = currentState;
    currentState = state;
}