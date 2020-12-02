#ifndef __PROXIMITY_H_
#define __PROXIMITY_H_

#include "SmartExperiment.h"

class Proximity {

public:
    virtual bool isMotionDetected() = 0;
};

#endif // __PROXIMITY_H_
