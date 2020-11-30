#include "DetectObjectDistanceTask.h"

void DetectObjectDistanceTask::tick() {
    if ( this->hasMediator() )
        taskDirector.notifyObjectDetectedChange(*this, sonar->computeDistance());
    else
        log("No mediator set for: ", typeid(this).name());
}