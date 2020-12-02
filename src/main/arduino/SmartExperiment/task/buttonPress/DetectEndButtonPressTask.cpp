#include "DetectEndButtonPressTask.h"

void DetectEndButtonPressTask::tick() {
    if ( this->hasMediator() )
        taskDirector->notifyEndButtonPression(button->isPressed());
    else
        log("No mediator set for DetectEndButtonPressTask object");
}