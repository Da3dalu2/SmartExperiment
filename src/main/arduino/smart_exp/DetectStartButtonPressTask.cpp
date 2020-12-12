#include "DetectStartButtonPressTask.h"

void DetectStartButtonPressTask::tick() {
    if ( this->hasMediator() ) {
        if (button->isPressed()) {
            taskDirector->notifyStartButtonPression(button->isPressed());
            Serial.println(button->isPressed());
        }
    } else
        logger.log("No mediator set for DetectStartButtonPressTask object");
}