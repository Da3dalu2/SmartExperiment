#ifndef __BUTTONIMPL_H_
#define __BUTTONIMPL_H_

#include "Button.h"

class ButtonImpl: public Button {

public: 
     ButtonImpl(uint8_t pin, uint16_t delay);
     bool isPressed();

private:
     uint8_t pin;
     uint8_t lastStableState;
     uint8_t lastUnstableState;
     uint16_t lastDebounceTime;
     uint16_t debounceDelay;
};

#endif // __BUTTONIMPL_H_
