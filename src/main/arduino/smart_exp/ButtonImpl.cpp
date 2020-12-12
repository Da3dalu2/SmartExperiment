#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(uint8_t pin, uint16_t delay) {
     this->pin = pin;
     this->currentState = LOW;
     this->lastStableState = LOW;
     this->lastUnstableState = LOW;
     this->lastDebounceTime = 0;
     this->debounceDelay = delay;
     this->pressed = false;

     pinMode(pin, INPUT); 
} 

bool ButtonImpl::isPressed() {
     currentState = digitalRead(pin);

     if( currentState != lastUnstableState ) {
          lastDebounceTime = millis();
          lastUnstableState = currentState;
     }

     if( (millis() - lastDebounceTime) > debounceDelay ) {

          if( currentState == LOW) {
               pressed = false;
          } else {
               pressed = true;
          }
          lastStableState = currentState;
     }

     return pressed;   
}