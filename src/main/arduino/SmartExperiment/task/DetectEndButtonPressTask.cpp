#include "DetectEndButtonPressTask.h"

void DetectEndButtonPressTask::tick() {
    if ( this->hasMediator() )
        taskDirector.notifyEndButtonPression(*this, button->isPressed());
    else
        log("No mediator set for: ", typeid(this).name());
}