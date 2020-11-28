#ifndef __BUTTON_H_
#define __BUTTON_H_

#include "SmartExperiment.h"
#include "Debounced.h"

class Button: public Debounced {

public: 
     virtual bool isPressed() = 0;
};

#endif  // __BUTTON_H_
