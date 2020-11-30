#ifndef __SONAR_H_
#define __SONAR_H_

#include "SmartExperiment.h"

class Sonar {

public:
    virtual float computeDistance() = 0;
    virtual void calibrate(float updateTemperatureCelsius) = 0;
    virtual bool isObjectDetected() = 0;
};

#endif // __SONAR_H_
