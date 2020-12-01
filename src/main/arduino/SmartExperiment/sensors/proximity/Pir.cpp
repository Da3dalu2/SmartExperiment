#include "Pir.h"

#define CALIBRATION_TIME 20

Pir::Pir(uint8_t pin) {
    this->pirState = LOW;
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Pir::isMotionDetected() {
    bool sensor_value = digitalRead(pin);
    if ( sensor_value != pirState )
        pirState = sensor_value;
    return pirState;
}

void Pir::calibrate() {
    delay(CALIBRATION_TIME * 1000);
}
