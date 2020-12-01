#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

#include "Task.h"
#include "SchedulerManager.h"
#include "Timer.h"

#define MAX_TASKS 50

class Scheduler {
  
public:
     Scheduler(SchedulerManager* schedMgr);
     void init(uint16_t basePeriod);  
     bool addTask(Task* task);
     bool rmvTask(Task* task);
     void schedule();
     Task* getTaskList();

private:
     void sleep();
     uint8_t basePeriod;
     uint8_t nTasks;
     SchedulerManager* schedMgr;
     Task* taskList[MAX_TASKS];
};

#endif  // __SCHEDULER_H_
