#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

#include "Task.h"
#include <avr/sleep.h>
#include <avr/power.h>
#include <libs/Timer1.h>
#define MAX_TASKS 50

class Scheduler {
  
public:
     void init(uint16_t basePeriod);  
     virtual bool addTask(Task* task);  
     virtual void schedule();

private:
     void sleep();
     int basePeriod;
     int nTasks;
     Task* taskList[MAX_TASKS];  

};

#endif  // __SCHEDULER_H_
