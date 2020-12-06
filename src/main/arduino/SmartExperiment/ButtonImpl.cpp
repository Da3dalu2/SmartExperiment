#include "ButtonImpl.h"
#include "Arduino.h"

/**
 * If delay is 50 and the period of the task is 10, debounceDelay must be 5.
 * So delay should be 5 and should be set by the task that knows its period.
 */ 
ButtonImpl::ButtonImpl(uint8_t pin, uint16_t delay) {
     this->pin = pin;
     this->currentState = LOW;
     /*this->lastStableState = LOW;
     this->lastUnstableState = LOW;
     this->lastDebounceTime = 0;
     this->debounceDelay = delay;
     this->pressed = false;*/

     pinMode(pin, INPUT); 
} 

void ButtonImpl::updateState() {
     uint8_t currentState = digitalRead(pin);
}

bool ButtonImpl::isPressed() {
     this->updateState();
     return currentState;
}