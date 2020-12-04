#ifndef __SCHEDULER_MANAGER_H_
#define __SCHEDULER_MANAGER_H_

#include "Observer.h"
#include "EnumState.h"
#include "UpdateStatusTask.h"
#include "DisplayStatusTask.h"
#include "DetectStartButtonPressTask.h"
#include "DetectEndButtonPressTask.h"
#include "ComputeDataTask.h"
#include "SendDataTask.h"
#include "DetectMotionTask.h"
#include "DetectObjectDistanceTask.h"
#include "DetectObjectPresenceTask.h"
#include "DisplaySpeedTask.h"
#include "SetSamplingFrequencyTask.h"
#include "Scheduler.h"
#include "ViewerStatus.h"
#include "MicrocontrollerStatus.h"
#include "TaskDirector.h"
#include <LinkedList.h>

/**
 * Observers updateStatusTask. Updates scheduler's taskList.
 */
class SchedulerManager: public Observer {

public:
    SchedulerManager(Scheduler* sched);
    void init();
    void checkScheduling();
    void update(UpdateStatusTask& task);

private:
    void populateLists();
    void check(bool opSucceded);
    const uint8_t pirPin = 13;
    const uint8_t startLedPin = 8;
    const uint8_t endLedPin = 7;
    const uint8_t startButtonPin = 4;
    const uint8_t endButtonPin = 5;
    const uint8_t echoPin = 2;
    const uint8_t trigPin = 12;
    const uint8_t tempPin = A4;
    const uint8_t potPin = A1;
    const uint8_t servoPin = 3;
    const uint16_t debounceDelay = 50; //ms
    LinkedList<Task*> readyStateTaskList;
    LinkedList<Task*> runningStateTaskList;
    Task* suspendedStateTask;
    UpdateStatusTask* updateStatusTask;
    DisplayStatusTask* displayStatusTask;
    Scheduler* sched;
    EnumState currentState;
    EnumState previousState;
};

#endif // __SCHEDULER_MANAGER_H_