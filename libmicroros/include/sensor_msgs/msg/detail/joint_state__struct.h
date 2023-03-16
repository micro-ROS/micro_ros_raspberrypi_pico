// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensor_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_
#define SENSOR_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "rosidl_runtime_c/type_hash.h"


// Type Version Hash for interface
// Note: this define is for MSVC, where the static const var can't be used in downstream aggregate initializers
#define sensor_msgs__msg__JointState__TYPE_VERSION_HASH__INIT {1, { \
      0x17, 0x49, 0x08, 0xb5, 0x4f, 0xf0, 0x43, 0x4c, \
      0x84, 0x17, 0x0d, 0xa2, 0x4a, 0x6d, 0xf4, 0x08, \
      0x38, 0xf1, 0x0c, 0x8e, 0xf2, 0x7d, 0x9a, 0xce, \
      0x5a, 0xe5, 0x19, 0xb2, 0x4b, 0xee, 0x63, 0x5a, \
    }}
static const rosidl_type_hash_t sensor_msgs__msg__JointState__TYPE_VERSION_HASH = sensor_msgs__msg__JointState__TYPE_VERSION_HASH__INIT;

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'position'
// Member 'velocity'
// Member 'effort'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/JointState in the package sensor_msgs.
/**
  * This is a message that holds data to describe the state of a set of torque controlled joints.
  *
  * The state of each joint (revolute or prismatic) is defined by:
  *  * the position of the joint (rad or m),
  *  * the velocity of the joint (rad/s or m/s) and
  *  * the effort that is applied in the joint (Nm or N).
  *
  * Each joint is uniquely identified by its name
  * The header specifies the time at which the joint states were recorded. All the joint states
  * in one message have to be recorded at the same time.
  *
  * This message consists of a multiple arrays, one for each part of the joint state.
  * The goal is to make each of the fields optional. When e.g. your joints have no
  * effort associated with them, you can leave the effort array empty.
  *
  * All arrays in this message should have the same size, or be empty.
  * This is the only way to uniquely associate the joint name with the correct
  * states.
 */
typedef struct sensor_msgs__msg__JointState
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String__Sequence name;
  rosidl_runtime_c__double__Sequence position;
  rosidl_runtime_c__double__Sequence velocity;
  rosidl_runtime_c__double__Sequence effort;
} sensor_msgs__msg__JointState;

// Struct for a sequence of sensor_msgs__msg__JointState.
typedef struct sensor_msgs__msg__JointState__Sequence
{
  sensor_msgs__msg__JointState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensor_msgs__msg__JointState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSOR_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_
