#ifndef __DETECT_BUTTON_PRESS_TASK_H_
#define __DETECT_BUTTON_PRESS_TASK_H_

#include "Task.h"
#include "ButtonImpl.h"
#include "TaskDirector.h"
#include "Communicator.h"

class DetectButtonPressTask: public Task, public Communicator {

public: 
    DetectButtonPressTask(uint8_t buttonPin, uint16_t debounceDelay) {
        this->buttonPin = buttonPin;
        this->debounceDelay = debounceDelay;
    };
    
    void init(uint16_t period) {
        Task::init(period);
        this->button = new ButtonImpl(buttonPin, debounceDelay);
    };

protected:
    ButtonImpl* button;

private:
    uint16_t debounceDelay;
    uint8_t buttonPin;
};

#endif // __DETECT_BUTTON_PRESS_TASK_H_