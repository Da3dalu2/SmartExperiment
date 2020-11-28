#include "Scheduler.h"

Scheduler* scheduler;

void setup() {
    Serial.begin(9600);
    scheduler = new Scheduler();
    scheduler->init(50);
}

void loop() {
    scheduler->schedule();
};
