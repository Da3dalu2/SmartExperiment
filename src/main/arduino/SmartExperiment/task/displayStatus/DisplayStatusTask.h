#ifndef __DISPLAYSTATUS_TASK_H_
#define __DISPLAYSTATUS_TASK_H_

#include "Task.h"
#include "Observer.h"
#include "State.h"
#include "MicrocontrollerStatus.h"
#include "ViewerStatus.h"
#include "EnumState.h"

class DisplayStatusTask: public Task, public Observer {

public:
     DisplayStatusTask(  MicrocontrollerStatus* microStatus, 
                         ViewerStatus* viewerStatus);  
     void init(uint16_t period);  
     void tick();
     void update(UpdateStatusTask& task);

private:
     EnumState currentState;
     MicrocontrollerStatus* microStatus;
     ViewerStatus* viewerStatus;
};

#endif // __DISPLAYSTATUS_TASK_H_