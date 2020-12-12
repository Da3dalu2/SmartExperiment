#ifndef __PIR_H_
#define __PIR_H_

#include "Proximity.h"

class Pir: public Proximity {
 
public: 
    Pir(uint8_t pin);
    bool isMotionDetected();
    void calibrate();

private:
    uint8_t pin;
};

#endif // __PIR_H_

