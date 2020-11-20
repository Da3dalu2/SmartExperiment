#ifndef __SONAR_H_
#define __SONAR_H_

#include "../../SmartExperiment.h"

class Sonar {

public:
  virtual float getDistance() = 0;
  virtual void calibrate(uint8_t updatedTemperatureCelsius);

};

#endif // __SONAR_H_
