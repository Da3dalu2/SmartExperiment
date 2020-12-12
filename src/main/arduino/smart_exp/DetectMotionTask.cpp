#include "DetectMotionTask.h"

// file scope static variable
volatile bool movement;

void onMotionDetected() {
    movement = true;
    sleep_disable();
}

DetectMotionTask::DetectMotionTask(uint8_t pin) {
    this->pin = pin;
    movement = false;
    this->pir = new Pir(pin);
}

void DetectMotionTask::init(uint16_t period) {
    Task::init(period); 
    pir->calibrate();
}

void DetectMotionTask::attachInterruptToPir() {
    attachInterrupt(digitalPinToInterrupt(pin), onMotionDetected, RISING);
}

void DetectMotionTask::detachInterruptFromPir() {
    detachInterrupt(digitalPinToInterrupt(pin));
}

void DetectMotionTask::tick() {
    noInterrupts();
    if ( movement ) {
        movement = false;
        detachInterrupt(digitalPinToInterrupt(pin));
        taskDirector->notifyMotionDetectedChange(pir->isMotionDetected());
    }
    interrupts();
}