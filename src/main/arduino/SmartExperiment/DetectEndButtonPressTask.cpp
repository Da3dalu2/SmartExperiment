#include "DetectEndButtonPressTask.h"

void DetectEndButtonPressTask::tick() {
    if ( this->hasMediator() )
        taskDirector->notifyEndButtonPression(button->isPressed());
    else
        logger.log("No mediator set for DetectEndButtonPressTask object");
}