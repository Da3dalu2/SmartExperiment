#ifndef __DETECT_OBJECT_DISTANCE_TASK_H_
#define __DETECT_OBJECT_DISTANCE_TASK_H_

#include "DetectObjectTask.h"

class DetectObjectDistanceTask: public DetectObjectTask {

public:
    using DetectObjectDistanceTask::DetectObjectDistanceTask;
    void tick();
};

#endif // __DETECT_OBJECT_DISTANCE_TASK_H_