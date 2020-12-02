#include "BlinkLed.h"

BlinkLed::BlinkLed(uint8_t pin) {
     this->pin = pin;
}
  
void BlinkLed::init() {
     led = new Led(pin); 
     state = OFF;    
}

void BlinkLed::tick() {
     if ( state ) {
          led->switchOn();
          state = ON; 
     } else {
          led->switchOff();
          state = OFF;
     }
}