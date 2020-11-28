#ifndef __SONAR_H_
#define __SONAR_H_

#include "SmartExperiment.h"
#include "Calibrable.h"
#include "Interruptible.h"

class Sonar: public Calibrable, public Interruptible {

public:
  virtual float computeDistance();
};

#endif // __SONAR_H_
