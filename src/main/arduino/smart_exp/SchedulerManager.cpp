#include "SchedulerManager.h"

SchedulerManager::SchedulerManager() {
    this->currentState = EnumState::Ready;
    this->previousState = EnumState::Ending;
    this->readyStateTaskList = *new LinkedList<Task*>();
    this->runningStateTaskList = *new LinkedList<Task*>();
}

void SchedulerManager::init(Scheduler* sched) {
    this->sched = sched;

    /**
     * Creation and addition to the task list of updateStatusTask 
     * and displayStatusTask.
     * 
     * The creation is done only once.
     */ 
    updateStatusTask = new UpdateStatusTask();
    MicrocontrollerStatus* microStatus = new MicrocontrollerStatus(
        startLedPin, endLedPin);
    ViewerStatus* viewerStatus = new ViewerStatus();
    displayStatusTask = new DisplayStatusTask(
        microStatus, viewerStatus);

    TaskDirector* taskDirector = new TaskDirector();

    sched->addTask(updateStatusTask);
    sched->addTask(displayStatusTask);

    /**
     * Updating communication infrastructure accordingly.
     * Done only once.
     */ 
    taskDirector->registerUpdateStatusTask(updateStatusTask);
    updateStatusTask->attachMediator(taskDirector);
    updateStatusTask->attachObserver(displayStatusTask);
    updateStatusTask->attachObserver(this);

    /**
     * Period of tasks.
     */ 
    updateStatusTask->init(50); // milliseconds
    displayStatusTask->init(50);

    /**
     * Add other secondary support tasks.
     */ 
    populateLists(taskDirector);

    /**
     * Suspended state handling
     */
    this->detectMotionTask = new DetectMotionTask(pirPin);
}

void SchedulerManager::populateLists(TaskDirector* taskDirector) {

    /**
     * Ready state task list initialization
     */ 
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

    detectStartButtonPressTask->attachMediator(taskDirector);
    //detectObjectPresenceTask->attachMediator(taskDirector);
    //setSamplingFrequencyTask->attachMediator(taskDirector);

    /**
     * Period of task
     */
    detectStartButtonPressTask->init(50);
    detectObjectPresenceTask->init(50);
    setSamplingFrequencyTask->init(50);

    /**
     * Running state task list initialization
     */
    /*op_succeded = true;
    DetectEndButtonPressTask* detectEndButtonPressTask =
        new DetectEndButtonPressTask(endButtonPin, debounceDelay);
    DetectObjectDistanceTask* detectObjectDistanceTask =
        new DetectObjectDistanceTask(trigPin, echoPin, tempPin);
    ComputeDataTask* computeDataTask = new ComputeDataTask();
    SendDataTask* sendDataTask = new SendDataTask();
    DisplaySpeedTask* displaySpeedTask = new DisplaySpeedTask(servoPin);

    op_succeded = op_succeded && runningStateTaskList.add(
        detectEndButtonPressTask);
    op_succeded = op_succeded && runningStateTaskList.add(
        detectObjectDistanceTask);
    op_succeded = op_succeded && runningStateTaskList.add(
        computeDataTask);
    op_succeded = op_succeded && runningStateTaskList.add(
        sendDataTask);
    op_succeded = op_succeded && runningStateTaskList.add(
        displaySpeedTask);

    check(op_succeded);

    updateStatusTask->attachObserver(detectObjectDistanceTask);
    computeDataTask->attachObserver(sendDataTask);
    computeDataTask->attachObserver(displaySpeedTask);

    taskDirector->registerComputeDataTask(computeDataTask);
    detectEndButtonPressTask->attachMediator(taskDirector);
    detectObjectDistanceTask->attachMediator(taskDirector);
    computeDataTask->attachMediator(taskDirector);
*/
    /**
     * Period of task
     */
   /* detectEndButtonPressTask->init();
    detectObjectDistanceTask->init();
    computeDataTask->init();
    sendDataTask->init();
    displaySpeedTask->init();*/

}

void SchedulerManager::check(bool op_succeded) {
    if ( !op_succeded )
       logger.log("Failed task insertion");
}

/**
 *  Clear the task list and update accordingly to the current state.
 */ 
void SchedulerManager::checkScheduling() {
    if (currentState != previousState ) {
        switch(currentState) {
            case EnumState::Ready:
                logger.log("Ready status");
                sched->clearTaskList();
                check(sched->addTaskList(readyStateTaskList));
                break;
            case EnumState::Running:
                logger.log("Running status");
                sched->clearTaskList();
                //check(sched->addTaskList(runningStateTaskList));
                break;
            case EnumState::Error:
                logger.log("Error status");
                sched->clearTaskList();
                break;
            case EnumState::Ending:
                logger.log("Ending status");
                sched->clearTaskList();
                break;
            case EnumState::Suspended:
                logger.log("Suspended status");
                sched->clearTaskList();
                check(sched->addTask(detectMotionTask));
                set_sleep_mode(SLEEP_MODE_PWR_DOWN);
                sleep_enable();
                detectMotionTask->attachInterruptToPir();
                sleep_mode();
                detectMotionTask->detachInterruptFromPir();
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