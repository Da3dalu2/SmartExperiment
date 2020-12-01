#ifndef __DETECT_ENDBUTTON_PRESS_TASK_H_
#define __DETECT_ENDBUTTON_PRESS_TASK_H_

#include "DetectButtonPressTask.h"

class DetectEndButtonPressTask: public DetectButtonPressTask {

public: 
    using DetectButtonPressTask::DetectButtonPressTask;
    void tick();

};

#endif // __DETECT_ENDBUTTON_PRESS_TASK_H_