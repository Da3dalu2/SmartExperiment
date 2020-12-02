#ifndef __TASK_DIRECTOR_MEDIATOR_H_
#define __TASK_DIRECTOR_MEDIATOR_H_

#include "Task.h"
#include "UpdateStatusTask.h"
#include "DetectMotionTask.h"
#include "DetectObjectPresenceTask.h"
#include "DetectObjectDistanceTask.h"
#include "DetectStartButtonPressTask.h"
#include "DetectEndButtonPressTask.h"
#include "ComputeDataTask.h"
#include "Logger.h"

class TaskDirector {

public:
    TaskDirector();
    void registerUpdateStatusTask(UpdateStatusTask* updateStatusTask);
    void deregisterUpdateStatusTask();
    void registerComputeDataTask(ComputeDataTask* computeDataTask);
    void deregisterComputeDataTask();
    void registerDetectObjectDistanceTask(
        DetectObjectDistanceTask* detectObjectDistanceTask);
    void deregisterDetectObjectDistanceTask();
    void notifyMotionDetectedChange(bool motionDetected);
    void notifyObjectDetectedChange(bool objectDetected);
    void notifyStartButtonPression(bool startButtonPressed);
    void notifyEndButtonPression(bool endButtonPressed);
    void notifyObjectDistanceChange(float distance, uint32_t time);
    void notifySamplingFrequencyChange(uint8_t samplingFrequency);
    void notifyEndConfirmationReceived(bool endConfirmationReceived)

private:
    void checkUpdateStatusTaskRegistration();
    void checkComputeDataTaskRegistration();
    void checkDetectObjectDistanceTaskRegistration();
    bool updateStatusTaskSet;
    bool computeDataTaskSet;
    bool detectObjectDistanceTaskSet;
    DetectObjectDistanceTask* detectObjectDistanceTask;
    UpdateStatusTask* updateStatusTask;
    ComputeDataTask* computeDataTask;
};

#endif // __TASK_DIRECTOR_MEDIATOR_H_