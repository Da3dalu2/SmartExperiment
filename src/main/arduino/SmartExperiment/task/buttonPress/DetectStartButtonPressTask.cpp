#include "DetectStartButtonPressTask.h"

void DetectStartButtonPressTask::tick() {
    if ( this->hasMediator() )
        taskDirector->notifyStartButtonPression(button->isPressed());
    else
        log("No mediator set for DetectStartButtonPressTask object");
}