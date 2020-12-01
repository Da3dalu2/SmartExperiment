#ifndef __DETECT_OBJECT_DISTANCE_TASK_H_
#define __DETECT_OBJECT_DISTANCE_TASK_H_

#include "DetectObjectTask.h"

class DetectObjectDistanceTask: public DetectObjectTask, public Observer {

public:
    using DetectObjectTask::DetectObjectTask;
    void update(UpdateStatusTask& subject);
    void tick();
private:
    State* currentState;
};

#endif // __DETECT_OBJECT_DISTANCE_TASK_H_