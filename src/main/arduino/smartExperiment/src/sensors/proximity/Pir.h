#ifndef __PIR_H_
#define __PIR_H_

#include "Proximity.h"

class Pir: public Proximity {
 
public: 
    Pir(uint8_t pin);
    bool detectMotion();

private:
    uint8_t pin;
    bool pirState;
};

#endif // __PIR_H_

