#include "Pir.h"

#define CALIBRATION_TIME 10

Pir::Pir(uint8_t pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Pir::isMotionDetected() {
   return digitalRead(pin);
}

void Pir::calibrate() {
    delay(CALIBRATION_TIME * 1000);
}
