#include "DetectObjectPresenceTask.h"

DetectObjectPresenceTask::DetectObjectPresenceTask(uint8_t trigPin, uint8_t echoPin, uint8_t tempPin) {
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    this->tempPin = tempPin;
    this->temperatureCelsius = 0;
    this->distance = 0.0;
    this->period = 0;
}

void DetectObjectPresenceTask::init(uint16_t period) {
        this->period = period;
        Task::init(period);
        this->tempSensor = new TempSensor(tempPin, voltage);
        temperatureCelsius = tempSensor->getTemperature();
        this->sonar = new SonarImpl(trigPin, echoPin, temperatureCelsius);
};

void DetectObjectPresenceTask::tick() {
     if ( this->hasMediator() )
        taskDirector->notifyObjectDetectedChange(sonar->isObjectDetected());
    else
        logger.log("No mediator set for DetectObjectPresenceTask object");
}

void DetectObjectPresenceTask::calibrate() {
    temperatureCelsius = tempSensor->getTemperature();
    sonar->calibrate(temperatureCelsius);
};