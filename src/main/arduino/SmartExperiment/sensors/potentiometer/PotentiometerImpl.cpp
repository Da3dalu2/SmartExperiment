#include "PotentiometerImpl.h"

PotentiometerImpl::PotentiometerImpl(uint8_t pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

uint16_t PotentiometerImpl::getValue() {
    return analogRead(pin);
}
