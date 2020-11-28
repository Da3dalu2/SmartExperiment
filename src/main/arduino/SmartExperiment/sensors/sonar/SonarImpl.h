#ifndef __SONARIMPL_H_
#define __SONARIMPL_H_

#include "Sonar.h"

class SonarImpl: public Sonar {

public: 
     SonarImpl(uint8_t trigPin, uint8_t echoPin,  \
               uint8_t currentTemperatureCelsius);
     float computeDistance();
     void calibrate();

private:
     float sound_speed;
     uint8_t currentTemperatureCelsius;
     uint8_t trigPin;
     uint8_t echoPin;

};

#endif // __SONARIMPL_H_
