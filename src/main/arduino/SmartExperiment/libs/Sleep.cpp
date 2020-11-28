#include "Sleep.h"

/**
 * |sleep_mode| should be one of SLEEP_MODE_PWR_DOWN or SLEEP_MODE_IDLE.
 */ 
void sleep(uint8_t sleep_mode) {
    set_sleep_mode(sleep_mode);
    sleep_enable();
    sleep_mode();
    sleep_disable();
}

