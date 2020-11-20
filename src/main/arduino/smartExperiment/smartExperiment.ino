#include <Arduino.h>
#include "src/SmartExperiment.h"
#include "src/actuators/light/Led.h"
#include "src/sensors/button/ButtonImpl.h"
#include "src/sensors/sonar/SonarImpl.h"
#include "src/actuators/servo/ServoMotorImpl.h"
#include "src/sensors/potentiometer/PotentiometerImpl.h"
#include "src/sensors/proximity/Pir.h"
#include "src/sensors/temperature/TempSensor.h"

const uint8_t trigPin = 8;
const uint8_t echoPin = 7;
const uint8_t ledPin = 13;
const uint8_t buttonPin = 7;
const uint8_t debounceDelay = 50;

ServoMotor *servoMotor;
Light *led;
Button *button;
Sonar *sonar;
Potentiometer *potentiometer;
Pir *pir;
Temperature *tempSensor;

void setup() {
    Serial.begin(9600);
    potentiometer = new PotentiometerImpl(A1);
    servoMotor = new ServoMotorImpl(11);
    sonar = new SonarImpl(trigPin, echoPin, 20);
    led = new Led(ledPin);
    button = new ButtonImpl(buttonPin, debounceDelay);
    pir = new Pir(13);
    tempSensor = new TempSensor(A4, 5.0);
}

void loop(){
    /*delay(1000);
    servoMotor->on();
    servoMotor->setPosition(0);
    delay(1000);
    servoMotor->setPosition(90);
    delay(1000);
    servoMotor->setPosition(180);*/

    float temp = tempSensor->getTemperature();
    Serial.print("current temperature is: ");
    Serial.println(temp);
    delay(5);
    
    /*uint16_t value = potentiometer->getValue();
    Serial.print("current value is: ");
    Serial.println(value);
    delay(2000);*/

    /*bool motion = pir->detectMotion();
    Serial.print("has motion? ");
    Serial.println(motion);
    delay(500);*/
    
    /*float distance = sonar->getDistance();
    Serial.print("current distance is: ");
    Serial.println(distance);
    delay(5);*/
  /*if (button->isPressed()){
    Serial.println("on");
    led->switchOn();
  } else {
    led->switchOff();
  }*/
};
