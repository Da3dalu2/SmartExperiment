#include "Scheduler.h"

/**
 * Rate-monotonic scheduling. Static. From minor to maior period.
 * Concurrent execution through interrupts.
 *
 * 1. Wire dependecies infrastructure;
 * 2. Deactivate initial unused tasks.
 *
 * NOTE: No |removeTask()|.
 */ 
void timerHandler(void){}

void Scheduler::init(uint16_t basePeriod) {
     this->basePeriod = basePeriod;
     uint32_t period = 1000l * basePeriod;
     Timer.initialize(period);
     Timer.attachInterrupt(timerHandler);
     nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
     if (nTasks < MAX_TASKS - 1){
          taskList[nTasks] = task;
          nTasks++;
          return true;
     } else
          return false; 
}
  
void Scheduler::schedule() {   
     sleep();
     Serial.println("AWAKE");
  
     for (uint8_t i = 0; i < nTasks; i++){
          if ( taskList[i]->isActive() &&       \
               taskList[i]->updateAndCheckTime(basePeriod) )
               taskList[i]->tick();
     }
}

void Scheduler::sleep(){
     delay(100); /* fix needed to make it work */

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
