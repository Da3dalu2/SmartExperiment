#include "DetectObjectPresenceTask.h"

void DetectObjectPresenceTask::tick() {
     if ( this->hasMediator() )
        taskDirector.notifyObjectDetectedChange(*this, sonar->isObjectDetected());
    else
        log("No mediator set for: ", typeid(this).name());
}