#ifndef __STATE_H_
#define __STATE_H_

#include "SmartExperiment.h"
#include "EnumState.h"
#include "Logger.h"

class State {

public:
    virtual void execute() = 0;
    virtual EnumState getState() = 0;
private:
    EnumState state;
};

#endif // __STATE_H_
