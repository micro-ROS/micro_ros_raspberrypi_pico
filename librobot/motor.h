#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define MAX_CYCLES 256

typedef struct
{
    uint8_t clockwise_pin;
    uint8_t counterclockwise_pin;
    uint8_t pwm_pin;
} motor;

void init_motor(motor *motor, int clockwise_pin,
                int counterclockwise_pin, int pwm_pin);

void forward_motor(motor *motor, int speed);

void backward_motor(motor *motor, int speed);

void stop_motor(motor *motor);

void brake_motor(motor *motor);

#endif