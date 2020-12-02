#include "Scheduler.h"

void timerHandler(void){}

Scheduler::Scheduler(SchedulerManager* schedMgr) {
     this->schedMgr = schedMgr;
}

void Scheduler::init(uint16_t basePeriod) {
     this->basePeriod = basePeriod;
     uint32_t period = 1000l * basePeriod;
     this->timer = new Timer();
     timer->setupPeriod(period);
     timer->attachInterrupt(timerHandler);
}

bool Scheduler::addTask(Task* task) {
     if (taskList.size() < maxTasks - 1){
          taskList.add(task);
          return true;
     } else
          return false; 
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

void Scheduler::schedule() {   
     sleep();
#ifdef DEBUG
     Serial.println("AWAKE");
#endif
     for (uint8_t i = 0; i < taskList.size(); i++){
          if ( taskList.get(i)->updateAndCheckTime(basePeriod) )
               taskList.get(i)->tick();
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

LinkedList<Task*> Scheduler::getTaskList() {
     return taskList;
}