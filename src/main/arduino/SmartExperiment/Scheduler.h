#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

#include "Task.h"
#include "SchedulerManager.h"
#include <TimerOne.h>
#include <LinkedList.h>
#include <avr/sleep.h>
#include <avr/power.h>

class SchedulerManager;

class Scheduler {
  
public:
     Scheduler(SchedulerManager* schedMgr);
     void init(uint16_t basePeriod);  
     bool addTask(Task* task);
     bool rmvTask(Task* task);
     bool addTaskList(LinkedList<Task*> taskList);
     void clearTaskList();
     void schedule();
     LinkedList<Task*> getTaskList();

private:
     void sleep();
     const uint8_t maxTasks = 50;
     uint16_t basePeriod;
     SchedulerManager* schedMgr;
     LinkedList<Task*> taskList;
};

#endif  // __SCHEDULER_H_