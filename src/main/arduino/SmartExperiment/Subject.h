#ifndef __SUBJECT_H_
#define __SUBJECT_H_

#include <iostream>
#include <vector>
#include "Observer.h"

class Subject {

public:
    virtual ~Subject() = default;
    void attachObserver(Observer& ob) {
        observers.push_back(&ob);
    }

    void detachObserver(Observer& ob) {
        observers.erase(std::remove(observers.begin(), observers.end(), &ob));
    }

    void notifyObservers() {
        for (Observer* ob : observers)
            ob.update(*this);
    }

private:
    std::vector<Observer*> observers;

};

#endif // __SUBJECT_H_

