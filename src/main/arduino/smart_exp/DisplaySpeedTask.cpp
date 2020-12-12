#include "DisplaySpeedTask.h"

DisplaySpeedTask::DisplaySpeedTask(uint8_t pin) {
    this->currentState = EnumState::Ready;
    this->pin = pin;
    this->currentSpeed = 0.0;
    this->lastSpeed = 0.0;
}

void DisplaySpeedTask::init(uint16_t period) {
    Task::init(period);
    servoMotor = new ServoMotorImpl(pin);
    servoMotor->on();
}

void DisplaySpeedTask::tick() {
    if ( lastSpeed != currentSpeed ) {
        servoMotor->setPosition(map(servoMotor->getPosition(),
         0, maxSpeed, 0, 180));
    }
}

void DisplaySpeedTask::update(ComputeDataTask* task) {
    lastSpeed = currentSpeed;
    currentSpeed = task->getSpeed();
}