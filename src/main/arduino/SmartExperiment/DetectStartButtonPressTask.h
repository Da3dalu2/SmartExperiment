#ifndef __DETECT_STARTBUTTON_PRESS_TASK_H_
#define __DETECT_STARTBUTTON_PRESS_TASK_H_

#include "DetectButtonPressTask.h"
#include  "Logger.h"

class DetectStartButtonPressTask: public DetectButtonPressTask {

public: 
    using DetectButtonPressTask::DetectButtonPressTask;
    void tick();
};

#endif // __DETECT_STARTBUTTON_PRESS_TASK_H_