#ifndef __SUBJECT_H_
#define __SUBJECT_H_

#include <LinkedList.h>
#include "Observer.h"

class Subject {

public:
    virtual Subject() = default;
    void attachObserver(Observer& ob) {
        observers.add(&ob);
    }

    void detachObserver(Observer& ob) {
        for (uint8_t i = 0; i < observers.size(); i++) {
            if ( observers[i] == ob )
                observers.remove(i);  
        }
    }

    void notifyObservers() {
        for (Observer* ob : observers)
            ob->update(*this);
    }

private:
    LinkedList<Observer*> observers;
};

#endif // __SUBJECT_H_

