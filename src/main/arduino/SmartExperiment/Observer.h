#ifndef __OBSERVER_H_
#define __OBSERVER_H_

#include "Subject.h"

class Observer {

public:
    virtual ~Observer() = default;
    virtual void update(Subject& subject) = 0;
        
};

#endif // __OBSERVER_H_
