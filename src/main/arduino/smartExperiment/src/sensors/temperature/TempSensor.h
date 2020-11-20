#ifndef __TEMP_SENSOR_H_
#define __TEMP_SENSOR_H_

#include "Temperature.h"

class TempSensor: public Temperature {

public:
     TempSensor(uint8_t pin, float vcc);
     float getTemperature();
    
private:
     uint8_t pin;
     float vcc;
  
};

#endif // __TEMP_SENSOR_H_
