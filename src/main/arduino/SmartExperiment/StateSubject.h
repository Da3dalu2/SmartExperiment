#ifndef __STATE_SUBJECT_H_
#define __STATE_SUBJECT_H_

#include "SmartExperiment.h"
#include <LinkedList.h>
#include "StateObserver.h"

class StateObserver;

class StateSubject {

public:
    void attachObserver(StateObserver* ob) {
        observers.add(ob);
    }

    void detachObserver(StateObserver* ob) {
        for (uint8_t i = 0; i < observers.size(); i++) {
            if ( observers.get(i) == ob )
                observers.remove(i);  
        }
    }

    virtual void notifyObservers() = 0;

protected:
    LinkedList<StateObserver*> observers;
};

#endif // __STATE_SUBJECT_H_

