#include "robot.h"
#include <stdio.h>

void forward_robot(robot *robot, int speed)
{
    forward_motor(&robot->motor_left, speed);
    forward_motor(&robot->motor_right, speed);
}

void backward_robot(robot *robot, int speed)
{
    backward_motor(&robot->motor_left, speed);
    backward_motor(&robot->motor_right, speed);
}

void left_robot(robot *robot, int speed)
{
    backward_motor(&robot->motor_left, speed);
    forward_motor(&robot->motor_right, speed);
}

void duck_left_robot(robot *robot, int speed)
{
    stop_motor(&robot->motor_left);
    forward_motor(&robot->motor_right, speed);
}

void right_robot(robot *robot, int speed)
{
    forward_motor(&robot->motor_left, speed);
    backward_motor(&robot->motor_right, speed);
}

void duck_right_robot(robot *robot, int speed)
{
    forward_motor(&robot->motor_left, speed);
    stop_motor(&robot->motor_right);
}

void brake_robot(robot *robot)
{
    brake_motor(&robot->motor_left);
    brake_motor(&robot->motor_right);
}

uint8_t read_sensors(sensor *wall, sensor *ground)
{
    uint8_t wall_data = read_sensor(wall);
    uint8_t ground_data = read_sensor(ground);
    printf("m: %d - g: %d ", wall_data, ground_data);

    return (wall_data << 3) + ground_data;
}