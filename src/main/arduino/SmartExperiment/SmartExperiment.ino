#include "Scheduler.h"
#include "SchedulerManager.h"
#include <map>

Scheduler* scheduler;
SchedulerManager* schedulerManager;
std::map<String, Task> map;

void setup() {
    Serial.begin(9600);
    schedulerManager = new SchedulerManager();
    scheduler = new Scheduler(schedulerManager);
    scheduler->init(50);
//  scheduler->addAllTask(taskBag.getTasks());
}

void loop() {
    scheduler->schedule();
};
