#ifndef __DETECT_OBJECT_DISTANCE_TASK_H_
#define __DETECT_OBJECT_DISTANCE_TASK_H_

#include "Task.h"
#include "SonarImpl.h"
#include "Communicator.h"
#include "TaskDirector.h"
#include "TempSensor.h"
#include "StateObserver.h"
#include "EnumState.h"

class UpdateStatusTask;

class DetectObjectDistanceTask: public StateObserver, public Communicator, public Task {

public:
    DetectObjectDistanceTask(uint8_t trigPin, uint8_t echoPin, uint8_t tempPin);
    void update(EnumState state);
    void tick();
    void updateSamplingFrequency(uint8_t samplingFrequency);
    void init(uint16_t period);
    void calibrate();

private:
    uint8_t samplingFrequency = 0;
    EnumState currentState;
    Sonar* sonar;
    uint16_t period;
    const uint8_t voltage = 5;
    uint8_t echoPin;
    uint8_t trigPin;
    uint8_t tempPin;
    float temperatureCelsius;
    float distance;
    TempSensor* tempSensor;
};

#endif // __DETECT_OBJECT_DISTANCE_TASK_H_