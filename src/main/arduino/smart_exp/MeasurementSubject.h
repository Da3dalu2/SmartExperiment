#ifndef __MEASUREMENT_SUBJECT_H_
#define __MEASUREMENT_SUBJECT_H_

#include "SmartExperiment.h"
#include <LinkedList.h>
#include "MeasurementObserver.h"

class MeasurementObserver;

class MeasurementSubject {

public:
    void attachObserver(MeasurementObserver* ob) {
        observers.add(ob);
    }

    void detachObserver(MeasurementObserver* ob) {
        for (uint8_t i = 0; i < observers.size(); i++) {
            if ( observers.get(i) == ob )
                observers.remove(i);  
        }
    }

    virtual void notifyObservers() = 0;

protected:
    LinkedList<MeasurementObserver*> observers;
};

#endif // __MEASUREMENT_SUBJECT_H_

