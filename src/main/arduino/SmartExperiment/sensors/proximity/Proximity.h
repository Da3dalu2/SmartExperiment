#ifndef __PROXIMITY_H_
#define __PROXIMITY_H_

#include "SmartExperiment.h"
#include "Interruptible.h"

class Proximity: public Interruptible {

public:
    virtual bool detectMotion();
};

#endif // __PROXIMITY_H_
