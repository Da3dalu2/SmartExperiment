#ifndef __SCHEDULER_MANAGER_H_
#define __SCHEDULER_MANAGER_H_

#include "Observer.h"
#include "EnumState.h"
#include "UpdateStatusTask.h"
#include "DisplaySpeedTask.h"
#include "DisplayStatusTask.h"
#include "Scheduler.h"
#include <LinkedList.h>

/**
 * Observers updateStatusTask. Updates scheduler's taskList.
 */ 
class SchedulerManager: public Observer {

public:
    SchedulerManager(Scheduler* sched);
    void checkScheduling();
    void update(UpdateStatusTask& task);

private:
    LinkedList<Task*> readyStateTaskList;
    LinkedList<Task*> runningStateTaskList;
    LinkedList<Task*> suspendedStateTask;
    Scheduler* sched;
    EnumState currentState;
};

#endif // __SCHEDULER_MANAGER_H_