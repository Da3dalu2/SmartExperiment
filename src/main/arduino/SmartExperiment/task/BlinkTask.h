#ifndef __BLINK_TASK_H_
#define __BLINK_TASK_H_

#include "Task.h"
#include "Led.h"

class BlinkTask: public Task {

public:
     BlinkTask(uint8_t pin);  
     void init(uint16_t period);  
     void tick();

private:
     Light* led;
     uint8_t pin;
     enum { ON, OFF } state;
  
};

#endif // __BLINK_TASK_H_

