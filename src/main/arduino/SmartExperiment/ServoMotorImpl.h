#ifndef __SERVO_MOTOR_IMPL_H_
#define __SERVO_MOTOR_IMPL_H_

#include "ServoMotor.h"
#include "ServoTimer2.h"

class ServoMotorImpl: public ServoMotor {

public:
     ServoMotorImpl(uint8_t pin);
     void on();
     void setPosition(uint8_t angle);
     uint8_t getPosition();
     void off();
    
private:
     uint8_t pin; 
     ServoTimer2 motor;
};

#endif // __SERVO_MOTOR_IMPL_H_
