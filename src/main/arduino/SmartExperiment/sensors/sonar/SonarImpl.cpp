#include "SonarImpl.h"
#include "Arduino.h"
#include <math.h>

/**
 * REVIEW: If delayMicroseconds uses Timer2 and the servo uses also the
 * same timer, what happens?
 */ 
SonarImpl::SonarImpl(uint8_t trigPin, uint8_t echoPin, \
                     uint8_t currentTemperatureCelsius) {
    this->currentTemperatureCelsius = currentTemperatureCelsius;
    this->variance = 0;
    
    this->trigPin = trigPin;
    pinMode(trigPin, OUTPUT);
    
    this->echoPin = echoPin;
    pinMode(echoPin, INPUT);
}

void SonarImpl::calibrate(float updatedTemperatureCelsius) {
    sound_speed = 331.45 + 0.62 * updatedTemperatureCelsius;
    float distance_values[numberSamples];
    for (uint8_t i = 0; i < numberSamples; i++)
        distance_values[i] = this->computeDistance();

    this->variance = computeVariance(distance_values);
}

float SonarImpl::computeDistance() {
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

bool SonarImpl::isObjectDetected() {
    return abs(this->computeDistance()) < variance;
}