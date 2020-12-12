#include "DetectObjectDistanceTask.h"

DetectObjectDistanceTask::DetectObjectDistanceTask(uint8_t trigPin, uint8_t echoPin, uint8_t tempPin) {
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    this->tempPin = tempPin;
    this->temperatureCelsius = 0;
    this->distance = 0.0;
    this->period = 0;
}

void DetectObjectDistanceTask::init(uint16_t period) {
    this->period = period;
    Task::init(period);
    this->tempSensor = new TempSensor(tempPin, voltage);
    temperatureCelsius = tempSensor->getTemperature();
    this->sonar = new SonarImpl(trigPin, echoPin, temperatureCelsius);
};

void DetectObjectDistanceTask::tick() {
    if ( currentState == EnumState::Running )
        taskDirector->notifyObjectDistanceChange(sonar->getDistance(), sonar->getTime());
}

void DetectObjectDistanceTask::update(EnumState state) {
    this->currentState = state;
}

void DetectObjectDistanceTask::updateSamplingFrequency(
    uint8_t samplingFrequency) {
    if ( currentState == EnumState::Ready )
        this->period = samplingFrequency;
}

void DetectObjectDistanceTask::calibrate() {
    temperatureCelsius = tempSensor->getTemperature();
    sonar->calibrate(temperatureCelsius);
};