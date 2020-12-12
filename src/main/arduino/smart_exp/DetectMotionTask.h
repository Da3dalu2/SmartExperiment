#ifndef __DETECT_MOTION_TASK_H_
#define __DETECT_MOTION_TASK_H_

#include "Task.h"
#include "Pir.h"
#include "TaskDirector.h"
#include "Communicator.h"
#include <avr/sleep.h>

class DetectMotionTask: public Task, public Communicator {

public:
    DetectMotionTask(uint8_t pin);
    void init(uint16_t period);
    void tick();
    void attachInterruptToPir();
    void detachInterruptFromPir();

private:
    Pir* pir;
    uint8_t pin;
};

#endif // __DETECT_MOTION_TASK_H_

