#include <stdio.h>

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int8.h>

#include <rmw_microros/rmw_microros.h>

#include "pico/stdlib.h"
#include "pico_wifi_transport.h"
#include "librobot/robot.h"

robot picobot;
action current_state = STOP;

rcl_publisher_t publisher;
rcl_subscription_t subscriber;

std_msgs__msg__Int8 msg_pub;
std_msgs__msg__Int8 msg_sub;

void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
    msg_pub.data = read_sensors(&picobot.wall, &picobot.ground);
    char buf[3];
    sprintf(buf, "%d", msg_pub.data);
    printf("%s ", buf);
    rcl_ret_t ret = rcl_publish(&publisher, &msg_pub, NULL);

    switch (current_state)
    {
    case STOP:
        brake_robot(&picobot);
        break;
    case FORWARD:
        forward_robot(&picobot, 50);
        break;
    case RIGHT:
        right_robot(&picobot, 45);
        break;
    case BACKWARD:
        backward_robot(&picobot, 50);
        break;
    case LEFT:
        left_robot(&picobot, 45);
        break;
    case DUCK_LEFT:
        duck_left_robot(&picobot, 50);
        break;
    case DUCK_RIGHT:
        duck_right_robot(&picobot, 50);
        break;
    default:
        break;
    }
}

void subscription_callback(const void *msgin)
{
    const std_msgs__msg__Int8 *msg = (const std_msgs__msg__Int8 *)msgin;

    current_state = msg->data;
}

int main()
{
    set_microros_wifi_transports("SSID", "PASSWORD", "PC IP ADDRESS", 4444);

    picobot.state = STOP;
    init_motor(&picobot.motor_left, 20, 19, 21);
    init_motor(&picobot.motor_right, 17, 18, 16);
    init_sensor(&picobot.wall, 26, 27, 28);
    init_sensor(&picobot.ground, 13, 12, 11);

    rcl_timer_t timer;
    rcl_node_t node;
    rcl_allocator_t allocator;
    rclc_support_t support;
    rclc_executor_t executor;

    allocator = rcl_get_default_allocator();

    // Wait for agent successful ping for 2 minutes.
    const int timeout_ms = 1000;
    const uint8_t attempts = 120;

    rcl_ret_t ret = rmw_uros_ping_agent(timeout_ms, attempts);

    if (ret != RCL_RET_OK)
    {
        // Unreachable agent, exiting program.
        printf("Agent unreachable. Exiting...");
        return ret;
    }

    rclc_support_init(&support, 0, NULL, &allocator);

    rclc_node_init_default(&node, "picobot_node", "", &support);

    rclc_subscription_init_best_effort(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
        "picobot/cmd_vel");

    rclc_publisher_init_best_effort(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
        "picobot/sensors");

    rclc_timer_init_default(
        &timer,
        &support,
        RCL_MS_TO_NS(100),
        timer_callback);

    rclc_executor_init(&executor, &support.context, 2, &allocator);
    rclc_executor_add_timer(&executor, &timer);
    rclc_executor_add_subscription(&executor, &subscriber, &msg_sub, &subscription_callback, ON_NEW_DATA);

    while (true)
    {
        rcl_ret_t ret = rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
    }
    return 0;
}