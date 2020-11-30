#include <stdint.h>

float computeVariance(float dataArray[]) {
    uint16_t array_lenght = sizeof(dataArray) / sizeof(float);
    float mean, tot, variance;
    for (uint8_t i = 0; i < array_lenght; i++)
        tot += dataArray[i];

    mean = tot / array_lenght;
    for (uint8_t i = 0; i < array_lenght; i++)
        variance += pow(dataArray[i] - mean, 2);

    variance /= array_lenght;
    return variance;
}