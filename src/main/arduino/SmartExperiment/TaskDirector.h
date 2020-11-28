#ifndef __TASK_DIRECTOR_MEDIATOR_H_
#define __TASK_DIRECTOR_MEDIATOR_H_

#include "Task.h"
#include "UpdateStatusTask.h"
#include "DetectMotionTask.h"
#include "DetectObjectTask.h"
#include "Logger.h"
#include <typeinfo>
#include <optional>

class TaskDirector {

public:
    TaskDirector();
    void registerUpdateStatusTask(std::optional<UpdateStatusTask*>);
    void deregisterUpdateStatusTask();
    void notifyMotionDetectedChange(UpdateStatusTask& s, bool d);
    void notifyObjectDetectedChange(UpdateStatusTask& s, bool d);

private:
    void checkUpdateStatusTask();
    std::optional<UpdateStatusTask*> oUpdateStatusTask;
};

#endif // __TASK_DIRECTOR_MEDIATOR_H_

