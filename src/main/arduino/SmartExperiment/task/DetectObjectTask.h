#ifndef __DETECT_OBJECT_TASK_H_
#define __DETECT_OBJECT_TASK_H_

#include "../Task.h"
#include "../sensors/sonar/SonarImpl.h"

class DetectObjectTask: public Task {

public:
    DetectMotionTask(uint8_t pin);
    void init(uint16_t period);
    void tick();
    bool isMotionDetected();
    
private:
    uint8_t pin;
    bool ;
    
};

#endif // __DETECT_OBJECT_TASK_H_


