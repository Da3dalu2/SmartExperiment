#include "Scheduler.h"
#include "SchedulerManager.h"

Scheduler* scheduler;
SchedulerManager* schedulerManager;

void setup() {
    Serial.begin(9600);
    schedulerManager = new SchedulerManager();
    scheduler = new Scheduler(schedulerManager);
    schedulerManager->init(scheduler);
    scheduler->init(1000); // MCM of all other tasks, milliseconds
}

void loop() {
    scheduler->schedule();
}
