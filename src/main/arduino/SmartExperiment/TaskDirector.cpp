#include "TaskDirector.h"

TaskDirector::TaskDirector() {
    this->oUpdateStatusTask = std::nullopt;
}

void TaskDirector::registerUpdateStatusTask(
    std::optional<UpdateStatusTask*> oUpdateStatusTask) {
    this->oUpdateStatusTask = oUpdateStatusTask;
}

void TaskDirector::registerDisplayErrorTask (
    std::optional<UpdateStatusTask*> oDisplayErrorTask) {
    this->oDisplayErrorTask = oDisplayErrorTask;
}

void TaskDirector::deregisterUpdateStatusTask() {
    this->oUpdateStatusTask = std::nullopt;
}

void TaskDirector::registerComputeDataTask(
    std::optional<ComputeDataTask*> oComputeDataTask) {
    this->oComputeDataTask = oComputeDataTask;
}

void TaskDirector::deregisterComputeDataTask() {
    this->oComputeDataTask = std::nullopt;
}

void TaskDirector::checkUpdateStatusTask() {
    if ( !oUpdateStatusTask )
        log("UpdateStatusTask not registered");
}

void TaskDirector::notifyMotionDetectedChange(  DetectMotionTask& sender,
                                                bool motionDetected) {
    checkUpdateStatusTask();
    if ( typeid(sender) == typeid(DetectMotionTask) )
        log("Illegal communication happened");
    else
        oUpdateStatusTask.value()->setMotionDetected(motionDetected);
}

void TaskDirector::notifyObjectDetectedChange(  DetectObjectPresenceTask& sender,
                                                bool objectDetected) {
    checkUpdateStatusTask();
    if ( typeid(sender) == typeid(DetectObjectPresenceTask) )
        log("Illegal communication happened");
    else
        oUpdateStatusTask.value()->setObjectDetected(objectDetected);
}

void TaskDirector::notifyStartButtonPression(   DetectStartButtonPressTask& sender,
                                                bool startButtonPressed) {
    checkUpdateStatusTask();
    if ( typeid(sender) == typeid(DetectStartButtonPressTask) )
        log("Illegal communication happened");
    else
        oUpdateStatusTask.value()->setObjectDetected(startButtonPressed);
}

void TaskDirector::notifyEndButtonPression( DetectEndButtonPressTask& sender, 
                                            bool endButtonPressed) {
    checkUpdateStatusTask();
    if ( typeid(sender) == typeid(DetectEndButtonPressTask) )
        log("Illegal communication happened");
    else
        oUpdateStatusTask.value()->setObjectDetected(endButtonPressed);
}

void TaskDirector::notifyObjectDistanceChange( DetectObjectDistanceTask& sender,
                                               float distance) {
    if ( typeid(sender) == typeid(DetectObjectDistanceTask) )
        log("Illegal communication happened");
    else
        oComputeDataTask.value()->updateDistance(distance);
}