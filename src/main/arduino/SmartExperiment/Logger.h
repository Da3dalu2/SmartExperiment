#ifndef __LOGGER_H_
#define __LOGGER_H_

#include "SmartExperiment.h"

class Logger {

public:

    void log(String msg) {
#ifdef DEBUG
        Serial.println(msg);
#endif
    };

    void logValue(String msg, uint16_t value) {
#ifdef DEBUG
        Serial.println(msg);
        Serial.print(value);
#endif
    }

    void logParam(String msg, String param) {
#ifdef DEBUG
        Serial.println(msg);
        Serial.print(param);
#endif
    }

};

extern Logger logger;

#endif // __LOGGER_H_