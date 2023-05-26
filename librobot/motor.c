#include "motor.h"

void init_motor(motor *motor, int clockwise_pin,
                int counterclockwise_pin, int pwm_pin)
{
    motor->clockwise_pin = clockwise_pin;
    motor->counterclockwise_pin = counterclockwise_pin;
    motor->pwm_pin = pwm_pin;

    gpio_init(motor->clockwise_pin);
    gpio_set_dir(motor->clockwise_pin, GPIO_OUT);
    gpio_pull_up(motor->clockwise_pin);

    gpio_init(motor->counterclockwise_pin);
    gpio_set_dir(motor->counterclockwise_pin, GPIO_OUT);
    gpio_pull_up(motor->counterclockwise_pin);

    gpio_set_function(motor->pwm_pin, GPIO_FUNC_PWM);
    gpio_pull_up(motor->pwm_pin);
    uint slice_num = pwm_gpio_to_slice_num(motor->pwm_pin);
    pwm_set_wrap(slice_num, MAX_CYCLES);
    pwm_set_gpio_level(motor->pwm_pin, 0);
    pwm_set_enabled(slice_num, 1);
}

void forward_motor(motor *motor, int speed)
{
    gpio_put(motor->clockwise_pin, 1);
    gpio_put(motor->counterclockwise_pin, 0);
    pwm_set_gpio_level(motor->pwm_pin, speed <= MAX_CYCLES - 1 ? speed : MAX_CYCLES - 1);
}

void backward_motor(motor *motor, int speed)
{
    gpio_put(motor->clockwise_pin, 0);
    gpio_put(motor->counterclockwise_pin, 1);
    pwm_set_gpio_level(motor->pwm_pin, speed <= MAX_CYCLES - 1 ? speed : MAX_CYCLES - 1);
}

void stop_motor(motor *motor)
{
    gpio_put(motor->clockwise_pin, 0);
    gpio_put(motor->counterclockwise_pin, 0);
    pwm_set_gpio_level(motor->pwm_pin, 0);
}

void brake_motor(motor *motor)
{
    gpio_put(motor->clockwise_pin, 1);
    gpio_put(motor->counterclockwise_pin, 1);
    pwm_set_gpio_level(motor->pwm_pin, 0);
}