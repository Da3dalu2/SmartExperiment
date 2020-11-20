#ifndef __POTENTIOMETERIMPL_H_
#define __POTENTIOMETERIMPL_H_

#include "Potentiometer.h"

class PotentiometerImpl: public Potentiometer {

public: 
     PotentiometerImpl(uint8_t pin);
     uint16_t getValue();

private:
     uint8_t pin;

};

#endif // __POTENTIOMETERIMPL_H_
