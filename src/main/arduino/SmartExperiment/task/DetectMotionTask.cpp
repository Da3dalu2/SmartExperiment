#include "DetectMotionTask.h"

// file scope static variable
static volatile bool movement;

DetectMotionTask::DetectMotionTask(uint8_t pin) {
    this->pin = pin;
    movement = false;
    this->pir = new Pir(pin);
}

void DetectMotionTask::init(uint16_t period) {
    Task::init(period); 
    pir->calibrate();
}

void DetectMotionTask::attachInterrupt() {
    attachInterrupt(digitalPinToInterrupt(pin), onMotionDetected, CHANGE);
}

void DetectMotionTask::detachInterrupt() {
    detachInterrupt(digitalPinToInterrupt(pin));
}

static void onMotionDetected() {
    movement = true;
}

void DetectMotionTask::tick() {
    noInterrupts();
    if ( movement ) {
        movement = false;
        taskDirector->notifyMotionDetectedChange(pir->isMotionDetected());
    }
    interrupts();
}

