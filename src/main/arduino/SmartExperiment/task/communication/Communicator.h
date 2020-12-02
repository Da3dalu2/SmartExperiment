#ifndef __COMMUNICATOR_H_
#define __COMMUNICATOR_H_

#include "TaskDirector.h"

/**
 * Used by tasks that communicate through a mediator.
 * The mediator should be explicitly set for each participating task.
 */ 
class Communicator {

public:
    Communicator() = default;
    void attachMediator(TaskDirector* taskDirector) {
        this->taskDirector = taskDirector;
        mediatorSet = true;
    };
    void detachMediator() {
        this->taskDirector = nullptr;
        mediatorSet = false;
    }
    bool hasMediator() {
        return mediatorSet;
    }

protected:
    TaskDirector* taskDirector;

private:
    bool mediatorSet = false;
};

#endif // __COMMUNICATOR_H_