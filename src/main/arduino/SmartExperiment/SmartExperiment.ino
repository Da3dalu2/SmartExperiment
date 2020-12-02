#include "Scheduler.h"
#include "SchedulerManager.h"

Scheduler* scheduler;
SchedulerManager* schedulerManager;

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
