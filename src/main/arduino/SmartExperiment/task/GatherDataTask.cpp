#include "GatherDataTask.h"

GatherDataTask::GatherDataTask(uint8_t trigPin, uint8_t echoPin,    \
                               uint8_t tempPin) {
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    this->tempPin = tempPin;
    this->temperatureCelsius = 0;
    this->distance = 0.0;
}

void GatherDataTask::init(uint8_t period) {
    Task::init(period);
    this->tempSensor = new TempSensorImpl(tempPin, VOLTAGE);
    temperatureCelsius = tempSensor.getTemperature();
    this->sonar = new SonarImpl(trigPin, echoPin, temperatureCelsius);
}

void GatherDataTask::tick() {
    distance = sonar->computeDistance();
}

void GatherDataTask::calibrate() {
    temperatureCelsius = tempSensor->getTemperature();
    sonar->calibrate(temperatureCelsius);
}

float GatherDataTask::getDistance() {
    return distance;
}
