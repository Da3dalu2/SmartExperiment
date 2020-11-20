#include "Pir.h"
#include <Arduino.h>

Pir::Pir(uint8_t pin) {
    this->pirState = LOW;
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Pir::detectMotion() {
    bool sensor_value = digitalRead(pin);
    if ( sensor_value != pirState ) {
        pirState = sensor_value;
    }
    return pirState;
}
