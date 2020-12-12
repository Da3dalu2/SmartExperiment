#include "UpdateStatusTask.h"

UpdateStatusTask::UpdateStatusTask() {
    this->startButtonPressed = false;
    this->objectDetected = false;
    this->endButtonPressed = false;
    this->motionDetected = false;
    this->endConfirmationReceived = false;
    this->exitConfirmed = false;
    this->currentState = new ReadyState(this);
}

void UpdateStatusTask::init(uint32_t period) {
    Task::init(period);
}

void UpdateStatusTask::tick() {
    //logger.log("[UPDATE-STATUS]: ");
    currentState->execute();
}

void UpdateStatusTask::updateState(State* nextState) {
    delete currentState;
    currentState = nextState;
    notifyObservers();
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

void UpdateStatusTask::setEndConfirmationReceived(bool endConfirmationReceived,
 bool exitConfirmed) {
    this->endConfirmationReceived = endConfirmationReceived;
    this->exitConfirmed = exitConfirmed;
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

bool UpdateStatusTask::isEndConfirmationReceived() {
    return endConfirmationReceived;
}

bool UpdateStatusTask::isExitConfirmed() {
    return exitConfirmed;
}

EnumState UpdateStatusTask::getCurrentState() {
    return currentState->getState();
}

void UpdateStatusTask::notifyObservers() {
    for (uint8_t i = 0; i < observers.size(); i++)
            observers.get(i)->update(getCurrentState());
}
