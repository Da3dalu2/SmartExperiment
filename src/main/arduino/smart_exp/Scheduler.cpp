#include "Scheduler.h"

bool volatile timerFlag;

void timerHandler(void){
  timerFlag = true;
}

Scheduler::Scheduler(SchedulerManager* schedMgr) {
     this->schedMgr = schedMgr;
     timerFlag = false;
}

void Scheduler::init(uint16_t basePeriod) {
     this->basePeriod = basePeriod;
     uint32_t period = 1000l * basePeriod;
     Timer1.initialize(period);
     Timer1.attachInterrupt(timerHandler);
}

bool Scheduler::addTask(Task* task) {
     if (taskList.size() < maxTasks - 1){
          taskList.add(task);
          return true;
     } else
          return false; 
}

bool Scheduler::addTaskList(LinkedList<Task*> taskList) {
    
    bool op_succeded = true;
    for (uint8_t i = 0; i < taskList.size(); i++) {
        op_succeded = op_succeded && addTask(taskList.get(i));
    }
    return op_succeded;
}

bool Scheduler::rmvTask(Task* task) {
     for (uint8_t i = 0; i < taskList.size(); i++) {
          if( taskList.get(i) == task) {
               taskList.remove(i);
               return true;
          }
     }
     return false;
}

void Scheduler::clearTaskList() {
     taskList.clear();
}

void Scheduler::schedule() {   
    while (!timerFlag){}
    timerFlag = false;

     for (uint8_t i = 0; i < taskList.size(); i++){
          if ( taskList.get(i)->updateAndCheckTime(basePeriod) )
               taskList.get(i)->tick();
     }

     schedMgr->checkScheduling();
}

LinkedList<Task*> Scheduler::getTaskList() {
     return taskList;
}
