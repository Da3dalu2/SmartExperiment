#ifndef __DISPLAYSPEED_TASK_H_
#define __DISPLAYSPEED_TASK_H_

#include "Task.h"
#include "Communicator.h"

class DisplaySpeedTask: public Task, public Communicator {
public:
     DisplaySpeedTask(uint8_t pin);  
     void init(uint16_t period);  
     void tick();
     void setErrorDetected(bool isErrorDetected, String errorDescription);
};

#endif // __DISPLAYSPEED_TASK_H_