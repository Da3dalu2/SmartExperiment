#ifndef __BUTTONIMPL_H_
#define __BUTTONIMPL_H_

#include "Button.h"

class ButtonImpl: public Button {

public: 
     ButtonImpl(uint8_t pin, uint16_t delay);
     bool isPressed();
     void updateState();

private:
     uint8_t pin;
     uint8_t currentState;
     /*uint8_t lastStableState;
     uint8_t lastUnstableState;
     bool pressed;
     uint16_t lastDebounceTime;
     uint16_t debounceDelay;*/
};

#endif // __BUTTONIMPL_H_
