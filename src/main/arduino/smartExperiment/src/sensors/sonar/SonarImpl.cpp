#include "SonarImpl.h"
#include "Arduino.h"

SonarImpl::SonarImpl(uint8_t trigPin, uint8_t echoPin, uint8_t currentTemperatureCelsius) {
    this->sound_speed = 331.45 + 0.62 * currentTemperatureCelsius;

    this->trigPin = trigPin;
    pinMode(trigPin, OUTPUT);
    
    this->echoPin = echoPin;
    pinMode(echoPin, INPUT);
}

void SonarImpl::calibrate(uint8_t updatedTemperatureCelsius) {
    sound_speed = 331.45 + 0.62 * updatedTemperatureCelsius;
}

float SonarImpl::getDistance() {
    float time, distance, pulse_time;
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);
    
    pulse_time = pulseInLong(echoPin, HIGH);
    time = pulse_time / 1000.0 / 1000.0 / 2;
    distance = time * sound_speed;
    
    return distance;
}
