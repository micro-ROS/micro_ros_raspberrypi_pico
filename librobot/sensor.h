#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "hardware/gpio.h"

typedef struct
{
    uint8_t left;
    uint8_t middle;
    uint8_t right;
} sensor;

void init_sensor(sensor *sensor, uint8_t left, uint8_t middle, uint8_t right);

uint8_t read_sensor(sensor* sensor);

#endif