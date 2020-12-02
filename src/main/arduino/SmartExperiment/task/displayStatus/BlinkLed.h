#ifndef __BLINKLED_H_
#define __BLINKLED_H_

#include "Led.h"

class BlinkLed {

public:
    BlinkLed(uint8_t pin);  
    void init();  
    void tick();

private:
    Light* led;
    uint8_t pin;
    enum { ON, OFF } state;
};

#endif // __BLINKLED_H_