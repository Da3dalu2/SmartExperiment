#include "SendDataTask.h"

SendDataTask::SendDataTask(float distance, float time) {
    this->distance = distance;
    this->time = time;
    this->msg = "";
}

void SendDataTask::init(uint8_t period) {
    Task::init(period);
    MsgService.init();
}

void SendDataTask::tick() {
    msg = distance + " " + time + "\n"
    MsgService.sendMsg(msg);
}

void SendDataTask::setTime(float time) {
    this->time = time;
}

void SendDataTask::setDistance(float distance) {
    this->distance = distance;
}
