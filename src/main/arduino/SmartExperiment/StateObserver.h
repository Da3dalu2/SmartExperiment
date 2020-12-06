#ifndef __STATE_OBSERVER_H_
#define __STATE_OBSERVER_H_

#include "StateSubject.h"
#include "EnumState.h"

class StateObserver {

public:
    virtual void update(EnumState state) = 0;
};

#endif // __STATE_OBSERVER_H_