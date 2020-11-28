#ifndef __LIGHT_H_
#define __LIGHT_H_

#include "../../SmartExperiment.h"

class Light {
public:
     virtual void switchOn() = 0;
     virtual void switchOff() = 0;    
};

#endif  // __LIGHT_H_

