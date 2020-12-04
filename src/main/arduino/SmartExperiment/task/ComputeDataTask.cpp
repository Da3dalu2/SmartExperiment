#include "ComputeDataTask.h"

ComputeDataTask::ComputeDataTask() {
    this->lastDistance = 0.0;
    this->lastTime = 0;
    this->lastSpeed = 0.0;
    this->speed = 0.0;
    this->acceleration = 0.0;
    this->distance = 0.0;
    this->timeElapsed = 0;
}

void ComputeDataTask::init(uint16_t period) {
    Task::init(period);
}

void ComputeDataTask::tick() {
    speed = ( distance - lastDistance ) / ( timeElapsed - lastTime );
    acceleration = ( speed - lastSpeed ) / ( timeElapsed - lastTime );
}

void ComputeDataTask::updateDistance(float newDistance, uint32_t newTime) {
    lastDistance = distance;
    lastTime = timeElapsed;
    lastSpeed = speed;

    distance = newDistance;
    timeElapsed = newTime;
    speed = 0.0;
}

uint32_t ComputeDataTask::getTime() {
    return timeElapsed;
}

float ComputeDataTask::getDistance() {
    return distance;
}

float ComputeDataTask::getSpeed() {
    return speed;
}

float ComputeDataTask::getAcceleration() {
    return acceleration;
}