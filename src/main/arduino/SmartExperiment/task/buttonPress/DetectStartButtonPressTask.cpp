#include "DetectStartButtonPressTask.h"

void DetectStartButtonPressTask::tick() {
    if ( this->hasMediator() )
        taskDirector.notifyStartButtonPression(*this, button->isPressed());
    else
        log("No mediator set for: ", typeid(this).name());
}