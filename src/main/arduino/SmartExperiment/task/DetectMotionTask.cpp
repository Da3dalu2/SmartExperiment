#include "DetectMotionTask.h"

/**
 * Should be activated with |active|.
 * Activates dependant tasks in |attachedActivables[]|.
 */

DetectMotionTask::DetectMotionTask(uint8_t pin) {
    this->pin = pin;
    this->movement = false;
}
 
void DetectMotionTask::init(uint16_t period) {
    Task::init(period);
    pir = new Pir(pin);
    pir.calibrate();
    pir.attachInterrupt(onMotionDetected);
}

void onMotionDetected() {
    movement = true;
}

void DetectMotionTask::tick() {
     switch (movement) {
     case false:
          if ( motionDetected )
               taskDirector.notifyMotionDetectedChange(false);
          break;
     case true:
          movement = false;
          taskDirector.notifyMotionDetectedChange(true);
          break;
     }
}

