#include "SonarImpl.h"

SonarImpl::SonarImpl(uint8_t trigPin, uint8_t echoPin,
                     uint8_t currentTemperatureCelsius) {
    this->currentTemperatureCelsius = currentTemperatureCelsius;
    this->variance = 0;
    this->time = 0;
    this->distance = 0;
    
    this->trigPin = trigPin;
    pinMode(trigPin, OUTPUT);
    
    this->echoPin = echoPin;
    pinMode(echoPin, INPUT);
}

void SonarImpl::calibrate(float updatedTemperatureCelsius) {
    sound_speed = 331.45 + 0.62 * updatedTemperatureCelsius;
    float distance_values[numberSamples];
    for (uint8_t i = 0; i < numberSamples; i++)
        distance_values[i] = this->getDistance();

    this->variance = computeVariance(distance_values, sizeof(distance_values)/sizeof(distance_values[0]));
}

float SonarImpl::getDistance() {
    float pulse_time;
    
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

uint32_t SonarImpl::getTime() {
    return time;
}

bool SonarImpl::isObjectDetected() {
    return abs(this->getDistance()) < variance;
}

float SonarImpl::computeVariance(float* dataArray, uint16_t array_length) {
    float mean, tot, variance;
    for (uint8_t i = 0; i < array_length; i++)
        tot += dataArray[i];

    mean = tot / array_length;
    for (uint8_t i = 0; i < array_length; i++)
        variance += pow(dataArray[i] - mean, 2);

    variance /= array_length;
    return variance;
}
