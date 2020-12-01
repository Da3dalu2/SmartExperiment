#ifndef __TASK_DIRECTOR_MEDIATOR_H_
#define __TASK_DIRECTOR_MEDIATOR_H_

#include "Task.h"
#include "UpdateStatusTask.h"
#include "DetectMotionTask.h"
#include "DetectObjectPresenceTask.h"
#include "DetectObjectDistanceTask.h"
#include "DetectStartButtonPressTask.h"
#include "DetectEndButtonPressTask.h"
#include "DisplayErrorTask.h"
#include "ComputeDataTask.h"
#include "Logger.h"
#include <typeinfo>
#include <optional>

class TaskDirector {

public:
    TaskDirector();
    void registerUpdateStatusTask(std::optional<UpdateStatusTask*>);
    void deregisterUpdateStatusTask();
    void registerComputeDataTask(
        std::optional<ComputeDataTask*> oComputeDataTask);
    void TaskDirector::deregisterComputeDataTask();
    void TaskDirector::registerDisplayErrorTask (
        std::optional<UpdateStatusTask*> oDisplayErrorTask);
    void TaskDirector::deregisterDisplayErrorTask();
    void notifyMotionDetectedChange(DetectMotionTask& sender,
                                    bool motionDetected);
    void notifyObjectDetectedChange(DetectObjectPresenceTask& sender, 
                                    bool objectDetected);
    void notifyStartButtonPression( DetectStartButtonPressTask& sender,
                                    bool startButtonPressed);
    void notifyEndButtonPression(   DetectEndButtonPressTask& sender,
                                    bool endButtonPressed);
    void notifyObjectDistanceChange(DetectObjectDistanceTask& sender, 
                                    float distance);

private:
    void checkUpdateStatusTask();
    std::optional<UpdateStatusTask*> oUpdateStatusTask;
    std::optional<ComputeDataTask*> oComputeDataTask;
    std::optional<DisplayErrorTask*> oDisplayErrorTask;
};

#endif // __TASK_DIRECTOR_MEDIATOR_H_

