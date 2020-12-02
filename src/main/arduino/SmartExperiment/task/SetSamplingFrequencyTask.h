#ifndef __SAMPLINGFREQUENCY_TASK_H_
#define __SAMPLINGFREQUENCY_TASK_H_

#include "Task.h"
#include "Observer.h"
#include "Communicator.h"
#include "UpdateStatusTask.h"
#include "State.h"
#include "PotentiometerImpl.h"

class SetSamplingFrequencyTask: public Task, public Observer, public Communicator {

public:
    SetSamplingFrequencyTask(uint8_t pin);  
    void init(uint16_t period);  
    void tick();
    void update(UpdateStatusTask& task);

private:
    const uint8_t minFreq = 10; // Hz
    const uint8_t maxFreq = 50; // Hz
    PotentiometerImpl* potentiometer;
    uint8_t pin;
    uint8_t lastChosenFrequency;
    uint8_t chosenFrequency; // minFreq < chosenFrequency < maxFreq
    EnumState currentState;
    TaskDirector* taskDirector;
};

#endif // __SAMPLINGFREQUENCY_TASK_H_

