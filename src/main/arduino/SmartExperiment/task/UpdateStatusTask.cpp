#include "UpdateStatusTask.h"

UpdateStatusTask::UpdateStatusTask() {
    this->startButtonPressed = false;
    this->objectDetected = false;
    this->endButtonPressed = false;
    this->motionDetected = false;
    this->oCurrentState = std::make_optional(new ReadyState(*this));
}

void UpdateStatusTask::init(uint16_t period) {
    Task::init(period);
}

void UpdateStatusTask::tick() {
    oCurrentState.value()->execute();
}

void UpdateStatusTask::updateState(State& nextState) {
    oCurrentState.emplace(&nextState);
}

void UpdateStatusTask::setMotionDetected(bool motionDetected) {
    this->motionDetected = motionDetected;
}

void UpdateStatusTask::setObjectDetected(bool objectDetected) {
    this->objectDetected = objectDetected;
}

void UpdateStatusTask::setStartButtonPressed(bool startButtonPressed) {
    this->startButtonPressed = startButtonPressed;
}

void UpdateStatusTask::setEndButtonPressed(bool endButtonPressed) {
    this->endButtonPressed = endButtonPressed;
}

bool UpdateStatusTask::isStartButtonPressed() {
    return startButtonPressed;
}

bool UpdateStatusTask::isEndButtonPressed() {
    return endButtonPressed;
}

bool UpdateStatusTask::isMotionDetected() {
    return motionDetected;
}

bool UpdateStatusTask::isObjectDetected() {
    return objectDetected;
}

State* UpdateStatusTask::getCurrentState() {
    return oCurrentState.value_or(new ReadyState(*this));
}
