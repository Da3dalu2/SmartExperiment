#include "DisplayStatusTask.h"

/**
 * Through composition this task is responsible of showing to the user the
 * status of the system both from the microcontroller and from the the 
 * Viewer application.
 */ 
DisplayStatusTask::DisplayStatusTask(   MicrocontrollerStatus* microStatus, 
                                        ViewerStatus* viewerStatus) {
    this->microStatus = microStatus;
    this->viewerStatus = viewerStatus;
    this->currentState = EnumState::Ready;
}

void DisplayStatusTask::init(uint32_t period) {
    Task::init(period);
    microStatus->init();
    viewerStatus->init();
}

void DisplayStatusTask::tick() {
    //logger.log("[DISPLAY-STATUS]: ");
    microStatus->displayStatus(currentState);
    viewerStatus->displayStatusOnViewer(currentState);
}

void DisplayStatusTask::update(EnumState state) {
    currentState = state;
}
