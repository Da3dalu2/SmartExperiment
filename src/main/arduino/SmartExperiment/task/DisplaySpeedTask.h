#ifndef __DISPLAYSPEED_TASK_H_
#define __DISPLAYSPEED_TASK_H_

#include "Task.h"
#include "EnumState.h"
#include "ComputeDataTask.h"
#include "ServoMotorImpl.h"
#include "Observer.h"

class DisplaySpeedTask: public Task, public Observer {

public:
     DisplaySpeedTask(uint8_t pin);  
     void init(uint16_t period);  
     void tick();
     void update(ComputeDataTask& task);

private:
     const uint8_t maxSpeed = 20; // m/s
     uint8_t pin;
     float lastSpeed;
     float currentSpeed;
     EnumState currentState;
     ServoMotorImpl* servoMotor;
};

#endif // __DISPLAYSPEED_TASK_H_