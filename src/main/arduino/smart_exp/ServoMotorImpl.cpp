#include "ServoMotorImpl.h"

ServoMotorImpl::ServoMotorImpl(uint8_t pin){
     this->pin = pin; 
} 

void ServoMotorImpl::on(){
     motor.attach(pin);    
}

void ServoMotorImpl::setPosition(uint8_t angle){
     uint16_t position = map(angle, 0, 180, 750, 2250);
     motor.write(position);
}

uint8_t ServoMotorImpl::getPosition() {
     uint16_t position = motor.read();
     return map(position, 750, 2250, 0, 180);
}

void ServoMotorImpl::off(){
     motor.detach();    
}
