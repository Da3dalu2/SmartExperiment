#ifndef __DETECT_OBJECT_PRESENCE_TASK_H_
#define __DETECT_OBJECT_PRESENCE_TASK_H_

#include "Task.h"
#include "SonarImpl.h"
#include "Communicator.h"
#include "TaskDirector.h"
#include "TempSensor.h"
#include "Logger.h"

class UpdateStatusTask;

class DetectObjectPresenceTask: public Communicator, public Task {

public:
    DetectObjectPresenceTask(uint8_t trigPin, uint8_t echoPin, uint8_t tempPin);
    void tick();
    void init(uint16_t period);
    void calibrate();

private:
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

#endif // __DETECT_OBJECT_PRESENCE_TASK_H_