#include "Scheduler.h"

/**
 * Rate-monotonic scheduling. Static. From minor to maior period.
 * List of tasks. Present are active, absent are inactive.
 * Looped by the scheduler.
 */ 
void timerHandler(void){}

Scheduler::Scheduler(SchedulerManager* schedMgr) {
     this->schedMgr = schedMgr;
     this->nTasks = 0;
}

void Scheduler::init(uint16_t basePeriod) {
     this->basePeriod = basePeriod;
     uint32_t period = 1000l * basePeriod;
     Timer.initialize(period);
     Timer.attachInterrupt(timerHandler);
}

bool Scheduler::addTask(Task* task) {
     if (nTasks < MAX_TASKS - 1){
          taskList[nTasks] = task;
          nTasks++;
          return true;
     } else
          return false; 
}

bool Scheduler::rmvTask(Task* task) {
     for (Task* elem : taskList) {
          if( elem == task) {
               taskList.remove(elem);
          }
     }
}

void Scheduler::schedule() {   
     sleep();
     Serial.println("AWAKE");

     for (Task* task : taskList){
          if ( task->updateAndCheckTime(basePeriod) )
               task->tick();
     }

     schedMgr->checkScheduling();
}

void Scheduler::sleep() {
     delayMicroseconds(100); /* fix needed to make it work */

     set_sleep_mode(SLEEP_MODE_IDLE);
     sleep_enable();

     power_adc_disable();
     power_spi_disable();
     power_timer0_disable();
     power_timer2_disable();
     power_twi_disable();  

     sleep_mode();  
     sleep_disable();
     power_all_enable();  
}

Task* Scheduler::getTaskList() {
     return *taskList;
}