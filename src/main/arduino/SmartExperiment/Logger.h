#ifndef __LOGGER_H_
#define __LOGGER_H_

void log(const char* msg) {
    Serial.println(msg);
};

void log(const char* msg, uint16_t value) {
    Serial.println(msg);
    Serial.print(value);
}

void log(const char* msg, const char* param) {
    Serial.println(msg);
    Serial.print(param);
}

#endif // __LOGGER_H_