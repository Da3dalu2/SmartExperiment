#include "Scheduler.h"
#include "SchedulerManager.h"
#include <list>

Scheduler* scheduler;
SchedulerManager* schedulerManager;
std::list<Task> taskList;

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
