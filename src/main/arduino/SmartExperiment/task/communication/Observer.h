#ifndef __OBSERVER_H_
#define __OBSERVER_H_

#include "Subject.h"

template<class Observer>
class Observer {

public:
    virtual void update(Subject* subject) = 0;
};

#endif // __OBSERVER_H_