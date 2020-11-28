#ifndef __DETECT_MOTION_TASK_H_
#define __DETECT_MOTION_TASK_H_

#include "../Task.h"
#include "../sensors/proximity/Pir.h"

class DetectMotionTask: public Task {

public:
    DetectMotionTask(uint8_t pin);
    void init(uint16_t period);
    void tick();
 
private:
    uint8_t pin;
    bool movement;
};

#endif // __DETECT_MOTION_TASK_H_

