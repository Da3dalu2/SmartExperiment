#ifndef __SENDDATA_TASK_H_
#define __SENDDATA_TASK_H_

#include "Task.h"
#include "MsgService.h"
#include "Observer.h"
#include "UpdateStatusTask.h"

class SendDataTask: public Task, public Observer {

public:
    SendDataTask();
    void init(uint16_t period);
    void tick();
    void update(ComputeDataTask& task);

private:
    String msg;
    float distance;
    float currentDistance;
    float currentSpeed;
    float currentAcceleration;
};

#endif // __SENDDATA_TASK_H_