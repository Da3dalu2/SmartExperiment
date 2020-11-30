#ifndef __COMMUNICATOR_H_
#define __COMMUNICATOR_H_

#include "TaskDirector.h"
#include <typeinfo>

/**
 * Used by tasks that communicate through a mediator.
 * The mediator should be explicitly set for each participating task.
 */ 
class Communicator {

public:
    Communicator() = default;
    void setMediator(TaskDirector& taskDirector) {
        this->taskDirector = taskDirector;
    };
    bool hasMediator() {
        return typeid(taskDirector) == typeid(TaskDirector);
    }

protected:
    TaskDirector taskDirector;

};

#endif // __COMMUNICATOR_H_