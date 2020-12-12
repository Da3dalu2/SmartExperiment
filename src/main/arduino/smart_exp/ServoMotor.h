#ifndef __SERVO_MOTOR_H_
#define __SERVO_MOTOR_H_

#include "SmartExperiment.h"

class ServoMotor {

public:
     virtual void on() = 0;
     virtual void setPosition(uint8_t angle) = 0;
     virtual uint8_t getPosition() = 0;
     virtual void off() = 0;
};

#endif // __SERVO_MOTOR_H_
