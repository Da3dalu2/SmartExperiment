#ifndef __DETECT_OBJECT_PRESENCE_TASK_H_
#define __DETECT_OBJECT_PRESENCE_TASK_H_

#include "DetectObjectTask.h"

class DetectObjectPresenceTask: public DetectObjectTask {

public:
    using DetectObjectTask::DetectObjectTask;
    void tick();
};

#endif // __DETECT_OBJECT_PRESENCE_TASK_H_