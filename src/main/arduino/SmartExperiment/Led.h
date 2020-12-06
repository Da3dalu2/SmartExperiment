#ifndef __LED_H_
#define __LED_H_

#include "Light.h"

class Led: public Light {
public:
    Led(uint8_t pin);
    void switchOn();
    void switchOff();
private:
    uint8_t pin;
};

#endif // __LED_H_
