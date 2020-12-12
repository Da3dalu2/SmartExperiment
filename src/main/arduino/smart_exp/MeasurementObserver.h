#ifndef __MEASUREMENT_OBSERVER_H_
#define __MEASUREMENT_OBSERVER_H_

#include "MeasurementSubject.h"
#include "EnumState.h"
#include "ComputeDataTask.h"

class ComputeDataTask;

class MeasurementObserver {

public:
    virtual void update(ComputeDataTask* task) = 0;
};

#endif // __MEASUREMENT_OBSERVER_H_