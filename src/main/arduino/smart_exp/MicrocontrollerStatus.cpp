#include "MicrocontrollerStatus.h"

MicrocontrollerStatus::MicrocontrollerStatus(uint8_t startLedPin, uint8_t endLedPin) {
    this->startLedPin = startLedPin;
    this->endLedPin = endLedPin;
    this->isHigh = false;
}

void MicrocontrollerStatus::init() {
    this->startLed = new Led(startLedPin);
    this->endLed = new Led(endLedPin);
}

void MicrocontrollerStatus::displayStatus(EnumState currentState) {
    switch(currentState) {
        case EnumState::Ready:
            startLed->switchOn();
            endLed->switchOff();
            break;
        case EnumState::Running:
            startLed->switchOff();
            endLed->switchOn();
            break;
        case EnumState::Error:
            startLed->switchOff();
            blink(endLed);
            break;
        case EnumState::Ending:
            startLed->switchOff();
            blink(endLed);
            break;
        case EnumState::Suspended:
            startLed->switchOff();
            endLed->switchOff();
            break;
    }
}

void MicrocontrollerStatus::blink(Led* led) {
    if (isHigh) {
        isHigh = false;
        led->switchOff();
    } else {
        isHigh = true;
        led->switchOn();
    }
}