#include "SendDataTask.h"

SendDataTask::SendDataTask() {
    this->distance = 0.0;
    this->currentTime = 0;
    this->currentDistance = 0.0;
    this->currentSpeed = 0.0;
    this->currentAcceleration = 0.0;
    this->msg = "";
}

void SendDataTask::init(uint16_t period) {
    Task::init(period);
    MsgService.init();
}

void SendDataTask::tick() {
    if (currentDistance != distance) {
        msg.concat(currentDistance);
        msg.concat(" ");
        msg.concat(currentSpeed);
        msg.concat(" ");
        msg.concat(currentAcceleration);
        msg.concat(" ");
        msg.concat(currentTime);
        msg.concat("\n");
        MsgService.sendMsg(msg);
    }
}

void SendDataTask::update(ComputeDataTask* task) {
    currentDistance = distance;
    distance = task->getDistance();
    currentSpeed = task->getSpeed();
    currentAcceleration = task->getAcceleration();
    currentTime = task->getTime();
}