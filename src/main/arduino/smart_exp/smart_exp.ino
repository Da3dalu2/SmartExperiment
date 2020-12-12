/**
 * Secondo progetto del corso di Sistemi Embedded e IoT
 * 
 * Autore: Riccardo Battistini <riccardo.battistini2@studio.unibo.it>
 */
#include "Scheduler.h"
#include "SchedulerManager.h"

Scheduler* scheduler;
SchedulerManager* schedulerManager;

void setup() {
    Serial.begin(9600);
    schedulerManager = new SchedulerManager();
    scheduler = new Scheduler(schedulerManager);
    schedulerManager->init(scheduler);
    scheduler->init(50); // MCM of all other tasks, milliseconds
}

void loop() {
    scheduler->schedule();
}
