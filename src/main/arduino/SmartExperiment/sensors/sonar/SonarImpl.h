#ifndef __SONARIMPL_H_
#define __SONARIMPL_H_

#include "Sonar.h"
#include "Utils.h"

class SonarImpl: public Sonar {

public: 
     SonarImpl(uint8_t trigPin, uint8_t echoPin,  \
               uint8_t currentTemperatureCelsius);
     float computeDistance();
     void calibrate(float updatedTemperatureCelsius);
     bool isObjectDetected();

private:
     const uint8_t numberSamples = 10;
     float sound_speed;
     float variance;
     uint8_t currentTemperatureCelsius;
     uint8_t trigPin;
     uint8_t echoPin;

};

#endif // __SONARIMPL_H_
