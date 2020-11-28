#include "TaskDirector.h"

TaskDirector::TaskDirector() {
    this->oUpdateStatusTask = std::nullopt;
}

void TaskDirector::registerUpdateStatusTask(    \
    std::optional<UpdateStatusTask*> oUpdateStatusTask) {
    this->oUpdateStatusTask = oUpdateStatusTask;
}

void TaskDirector::deregisterUpdateStatusTask() {
    this->oUpdateStatusTask = std::nullopt;
}

void TaskDirector::checkUpdateStatusTask() {
    if ( !oUpdateStatusTask )
        log("UpdateStatusTask not registered");
}

void TaskDirector::notifyMotionDetectedChange(UpdateStatusTask& sender, \
                                                      bool motionDetected) {
    checkUpdateStatusTask();
    if ( typeid(sender) == typeid(DetectMotionTask) )
        log("Illegal communication happened");
    else
        oUpdateStatusTask.value()->setMotionDetected(motionDetected);
}

void TaskDirector::notifyObjectDetectedChange(UpdateStatusTask& sender, \
                                                      bool objectDetected) {
    checkUpdateStatusTask();
    if ( typeid(sender) == typeid(DetectObjectTask) )
        log("Illegal communication happened");
    else
        oUpdateStatusTask.value()->setObjectDetected(objectDetected);
}
