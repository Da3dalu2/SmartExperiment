#ifndef __SCHEDULER_MANAGER_H_
#define __SCHEDULER_MANAGER_H_

#include "Observer.h"

/**
 * Observers updateStatusTask. Updates scheduler's taskList.
 */ 
class SchedulerManager: public Observer {

public:
    SchedulerManager();
    void checkScheduling();
};

#endif // __SCHEDULER_MANAGER_H_