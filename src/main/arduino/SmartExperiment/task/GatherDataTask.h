#ifndef __GATHERDATA_TASK_H_
#define __GATHERDATA_TASK_H_

#include "../Task.h"
//#include "../SmartExperiment.h"
#include "../sensors/sonar/SonarImpl.h"
#include "../sensors/temperature/TempSensor.h"
#define VOLTAGE 5.0

class GatherDataTask: public Task {

public:
    GatherDataTask(uint8_t echoPin, uint8_t trigPin, uint8_t tempPin);
    void init(uint8_t period);
    void tick();
    void calibrate();
    float getDistance();

private:
    uint8_t echoPin;
    uint8_t trigPin;
    uitn8_t tempPin;
    uint8_t temperatureCelsius;
    float distance;
    TempSensor* tempSensor;
    Sonar* sonar;
};

#endif // __GATHERDATA_TASK_H_
