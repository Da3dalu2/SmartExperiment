#ifndef __DETECT_OBJECT_TASK_H_
#define __DETECT_OBJECT_TASK_H_

#include "Task.h"
#include "SonarImpl.h"
#include "Communicator.h"
#include "TempSensor.h"

/**
 * Should a deallocator method be called?
 */ 
class DetectObjectTask: public Task, public Communicator {

public:
    DetectObjectTask::DetectObjectTask( uint8_t trigPin, 
                                        uint8_t echoPin,
                                        uint8_t tempPin) {
        this->echoPin = echoPin;
        this->trigPin = trigPin;
        this->tempPin = tempPin;
        this->temperatureCelsius = 0;
        this->distance = 0.0;
        this->period = 0;
    }
    void init(uint16_t period) {
        this->period = period;
        Task::init(period);
        this->tempSensor = new TempSensor(tempPin, voltage);
        temperatureCelsius = tempSensor->getTemperature();
        this->sonar = new SonarImpl(trigPin, echoPin, temperatureCelsius);
    };
    virtual void tick() = 0;
    void calibrate() {
        temperatureCelsius = tempSensor->getTemperature();
        sonar->calibrate(temperatureCelsius);
    };
    
protected:
    Sonar* sonar;
    uint16_t period;

private:
    const uint8_t voltage = 5;
    uint8_t echoPin;
    uint8_t trigPin;
    uint8_t tempPin;
    float temperatureCelsius;
    float distance;
    TempSensor* tempSensor;

};

#endif // __DETECT_OBJECT_TASK_H_