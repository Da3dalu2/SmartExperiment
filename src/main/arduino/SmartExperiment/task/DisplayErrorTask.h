#ifndef __DISPLAYERROR_TASK_H_
#define __DISPLAYERROR_TASK_H_

#include "Task.h"
#include "Communicator.h"

class DisplayErrorTask: public Task, public Communicator {
public:
     DisplayErrorTask(uint8_t pin);  
     void init(uint16_t period);  
     void tick();
     void setErrorDetected(bool isErrorDetected, String errorDescription);
};

#endif // __DISPLAYERROR_TASK_H_7  