#include "DetectObjectPresenceTask.h"

void DetectObjectPresenceTask::tick() {
     if ( this->hasMediator() )
        taskDirector->notifyObjectDetectedChange(sonar->isObjectDetected());
    else
        log("No mediator set for DetectObjectPresenceTask object");
}