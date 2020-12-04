#ifndef __SUBJECT_H_
#define __SUBJECT_H_

#include <LinkedList.h>
#include "Observer.h"

class Subject {

public:
    Subject() = default;
    void attachObserver(Observer* ob) {
        observers.add(ob);
    }

    void detachObserver(Observer* ob) {
        for (uint8_t i = 0; i < observers.size(); i++) {
            if ( observers.get(i) == ob )
                observers.remove(i);  
        }
    }

    void notifyObservers() {
        for (uint8_t i = 0; i < observers.size(); i++)
            observers.get(i)->update(*this);
    }

private:
    LinkedList<Observer*> observers;
};

#endif // __SUBJECT_H_

