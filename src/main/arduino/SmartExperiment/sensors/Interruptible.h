#ifndef __INTERRUPTIBLE_H_
#define __INTERRUPTIBLE_H_

#include <EnableInterrupt.h>

class Interruptible {

public:
    void Interruptible::attachInterrupt(void(*isr)(void)) {
        enableInterrupt(pin, isr, CHANGE);
    }

    void Interruptible::detachInterrupt() {
        disableInterrupt(pin);
    }

private:
    uint8_t pin;
};

#endif // __INTERRUPTIBLE_H_
