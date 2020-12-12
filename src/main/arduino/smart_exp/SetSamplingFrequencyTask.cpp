#include "SetSamplingFrequencyTask.h"

SetSamplingFrequencyTask::SetSamplingFrequencyTask(uint8_t pin) {
     this->pin = pin;
     this->lastChosenFrequency = 0;
     this->chosenFrequency = 0;
}

void SetSamplingFrequencyTask::init(uint16_t period) {
     Task::init(period);
     potentiometer = new PotentiometerImpl(pin); 
}

void SetSamplingFrequencyTask::tick() {
     if ( currentState == EnumState::Ready ) {
          lastChosenFrequency = chosenFrequency;
          chosenFrequency = map(potentiometer->getValue(),
               0, 1023, minFreq, maxFreq);
          if ( lastChosenFrequency != chosenFrequency )
               taskDirector->notifySamplingFrequencyChange(chosenFrequency);
     }
}

void SetSamplingFrequencyTask::update(EnumState state) {
     currentState = state;
}