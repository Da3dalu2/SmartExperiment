#ifndef __COMPUTE_DATA_H_
#define __COMPUTE_DATA_H_

#include "Task.h"
#include "Communicator.h"
#include "MeasurementSubject.h"

class ComputeDataTask: public Task, public Communicator, public MeasurementSubject {

public:
    ComputeDataTask();  
    void init(uint16_t period);  
    void tick();
    void updateDistance(float newDistance, uint32_t newTime);
    float getAcceleration();
    float getSpeed();
    float getDistance();
    uint32_t getTime();
    void notifyObservers();

private:
    float lastDistance;     // m
    float speed;            // m/s
    float lastSpeed;        // m/s
    float acceleration;     // m/s^2 
    float distance;         // m
    uint32_t timeElapsed;   // s
    uint32_t lastTime;      // s
};

#endif // __COMPUTE_DATA_H_