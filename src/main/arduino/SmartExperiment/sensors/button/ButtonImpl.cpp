#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(uint8_t pin, uint8_t delay) {
     this->pin = pin;
//   this->current_state = LOW;
     this->lastStableState = LOW;
     this->lastUnstableState = LOW;
     this->lastDebounceTime = 0;
     this->debounceDelay = delay;
     
     pinMode(pin, INPUT); 
} 

bool ButtonImpl::isPressed() {

     uint8_t current_state = digitalRead(pin);
     bool is_pressed = false;
     
     if( current_state != lastUnstableState ) {
          this->lastDebounceTime = millis();
          this->lastUnstableState = current_state;
          Serial.print("current unstable button state: ");
          Serial.println(lastUnstableState);
     }

     if( (millis() - lastDebounceTime) > debounceDelay ) {
          if ( current_state != lastStableState ) {
               if ( lastStableState == HIGH && current_state == LOW ) {     
                    Serial.print("Button pressed");
                    is_pressed = true;
               }
          }
          
          this->lastStableState = current_state;
     }

     return is_pressed;
}
