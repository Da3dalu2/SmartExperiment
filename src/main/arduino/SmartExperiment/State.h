#ifndef __STATE_H_
#define __STATE_H_

#include "EnumState.h"

class State {

public:
    State();
    virtual void execute() = 0;
    virtual EnumState getState() = 0;
private:
    EnumState state;
};

#endif // __STATE_H_
