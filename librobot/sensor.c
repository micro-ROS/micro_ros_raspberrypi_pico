#include "sensor.h"

void init_sensor(sensor *sensor, uint8_t left, uint8_t middle, uint8_t right)
{
    sensor->left = left;
    sensor->middle = middle;
    sensor->right = right;

    gpio_init(sensor->left);
    gpio_set_dir(sensor->left, GPIO_IN);
    gpio_pull_up(sensor->left);
    gpio_init(sensor->middle);
    gpio_set_dir(sensor->middle, GPIO_IN);
    gpio_pull_up(sensor->middle);
    gpio_init(sensor->right);
    gpio_set_dir(sensor->right, GPIO_IN);
    gpio_pull_up(sensor->right);
}

uint8_t read_sensor(sensor *sensor)
{
    uint8_t left = gpio_get(sensor->left);
    uint8_t middle = gpio_get(sensor->middle);
    uint8_t right = gpio_get(sensor->right);

    return (left << 2) + (middle << 1) + (right);
}