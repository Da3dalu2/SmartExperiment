#include "TempSensor.h"
#include "Arduino.h"

TempSensor::TempSensor(uint8_t pin, float vcc) {
     this->vcc = vcc;
     this->pin = pin;
     pinMode(pin, INPUT);
}

float TempSensor::getTemperature() {
     float value_volt, value_celsius;
     uint16_t sensor_value = analogRead(pin);
  
     value_volt = sensor_value * vcc / 1024.0;  
     value_celsius = ( value_volt - 0.5 ) * 100;
  
     return value_celsius;
}
