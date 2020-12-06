#include "TaskDirector.h"

TaskDirector::TaskDirector() {
    this->updateStatusTaskSet = false;
    this->computeDataTaskSet = false;
}

void TaskDirector::registerUpdateStatusTask(
    UpdateStatusTask* updateStatusTask) {
    this->updateStatusTask = updateStatusTask;
    updateStatusTaskSet = true;
}

void TaskDirector::deregisterUpdateStatusTask() {
    this->updateStatusTask = nullptr;
    updateStatusTaskSet = false;
}

void TaskDirector::registerComputeDataTask(
    ComputeDataTask* computeDataTask) {
    this->computeDataTask = computeDataTask;
    computeDataTaskSet = true;
}

void TaskDirector::deregisterComputeDataTask() {
    this->computeDataTask = nullptr;
    computeDataTaskSet = false;
}

void TaskDirector::registerDetectObjectDistanceTask(
    DetectObjectDistanceTask* detectObjectDistanceTask) {
    this->detectObjectDistanceTask = detectObjectDistanceTask;
    detectObjectDistanceTaskSet = true;
}

void TaskDirector::deregisterDetectObjectDistanceTask() {
    this->computeDataTask = nullptr;
    computeDataTaskSet = false;
}

void TaskDirector::checkUpdateStatusTaskRegistration() {
    if ( !updateStatusTaskSet )
        logger.log("UpdateStatusTask not registered");
}

void TaskDirector::checkComputeDataTaskRegistration() {
    if ( !computeDataTaskSet )
        logger.log("ComputeDataTask not registered");
}

void TaskDirector::checkDetectObjectDistanceTaskRegistration() {
    if ( !detectObjectDistanceTaskSet )
        logger.log("DetectObjectDistanceTask not registered");
}

void TaskDirector::notifyMotionDetectedChange(bool motionDetected) {
    checkUpdateStatusTaskRegistration();
    updateStatusTask->setMotionDetected(motionDetected);
}

void TaskDirector::notifyObjectDetectedChange(bool objectDetected) {
    checkUpdateStatusTaskRegistration();
    updateStatusTask->setObjectDetected(objectDetected);
}

void TaskDirector::notifyStartButtonPression(bool startButtonPressed) {
    checkUpdateStatusTaskRegistration();
    updateStatusTask->setObjectDetected(startButtonPressed);
}

void TaskDirector::notifyEndButtonPression(bool endButtonPressed) {
    checkUpdateStatusTaskRegistration();
    updateStatusTask->setObjectDetected(endButtonPressed);
}

void TaskDirector::notifyObjectDistanceChange(float distance, uint32_t time) {
    checkComputeDataTaskRegistration();
    computeDataTask->updateDistance(distance, time);
}

void TaskDirector::notifySamplingFrequencyChange(uint8_t samplingFrequency) {
    checkDetectObjectDistanceTaskRegistration();
    detectObjectDistanceTask->updateSamplingFrequency(samplingFrequency);
}

void TaskDirector::notifyEndConfirmationReceived(bool endConfirmationReceived, bool exitConfirmed) {
    updateStatusTask->setEndConfirmationReceived(endConfirmationReceived, exit);
}