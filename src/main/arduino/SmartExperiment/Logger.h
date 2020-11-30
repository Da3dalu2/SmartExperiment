#ifndef __LOGGER_H_
#define __LOGGER_H_

#include "string.h"

void log(String msg) {
    Serial.println(msg);
};

void log(String msg, uint16_t value) {
    Serial.println(msg);
    Serial.print(value);
}

void log(String msg, String param) {
    Serial.println(msg);
    Serial.print(param);
}

#endif // __LOGGER_H_