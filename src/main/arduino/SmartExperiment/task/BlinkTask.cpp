#include "BlinkTask.h"

BlinkTask::BlinkTask(uint8_t pin) {
     this->pin = pin;
}
  
void BlinkTask::init(uint16_t period) {
     Task::init(period);
     led = new Led(pin); 
     state = OFF;    
}

void BlinkTask::tick() {
     switch (state){
     case OFF:
          led->switchOn();
          state = ON; 
          break;
     case ON:
          led->switchOff();
          state = OFF;
          break;
     }
}
