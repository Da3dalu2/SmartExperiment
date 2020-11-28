#ifndef __SENDDATA_TASK_H_
#define __SENDDATA_TASK_H_

#include "../Task.h"
//#include "../SmartExperiment.h"
#include "../MsgService.h"

class SendDataTask: public Task {

public:
    SendDataTask(float distance, float time);
    void init(uint8_t period);
    void tick();
    void setTime();
    void setDistance();

private:
    String msg;
    float distance;
    float time;
};

#endif // __SENDDATA_TASK_H_
