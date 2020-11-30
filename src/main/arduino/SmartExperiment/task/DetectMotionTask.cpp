#include "DetectMotionTask.h"

// file scope static variable
static volatile uint8_t movement;

DetectMotionTask::DetectMotionTask(uint8_t pin) {
    this->pin = pin;
    movement = false;
    this->pir = new Pir(pin);
}

void DetectMotionTask::init(uint16_t period) {
    Task::init(period); 
    pir->calibrate();
    pir->attachInterrupt(onMotionDetected);
}

static void onMotionDetected() {
    movement = true;
}

void DetectMotionTask::tick() {
     if ( movement ) {
          movement = false;
          taskDirector.notifyMotionDetectedChange(  *this, 
                                                    pir->isMotionDetected());
     }
}

