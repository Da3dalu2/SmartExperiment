#ifndef __SONARIMPL_H_
#define __SONARIMPL_H_

#include "Sonar.h"

class SonarImpl: public Sonar {

public: 
     SonarImpl(uint8_t trigPin, uint8_t echoPin,  \
               uint8_t currentTemperatureCelsius);
     void calibrate(uint8_t updatedTemperatureCelsius);
     float getDistance();
  
private:
     float sound_speed;
     uint8_t trigPin;
     uint8_t echoPin;

};

#endif // __SONARIMPL_H_
