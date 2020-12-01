#ifndef __COMPUTE_DATA_H_
#define __COMPUTE_DATA_H_

#include "Task.h"
#include "Communicator.h"
#include "Subject.h"

class ComputeDataTask: public Task, public Communicator, public Subject {
public:
    ComputeDataTask();  
    void init(uint16_t period);  
    void tick();
    void updateDistance(float newDistance, uint32_t newTime);
    float getAcceleration();
    float getSpeed();
    float getDistance();
private:
    float lastDistance;
    float speed;
    float lastSpeed;
    float acceleration;
    float distance;
    uint32_t timeElapsed;
    uint32_t lastTime;
};

#endif // __COMPUTE_DATA_H_