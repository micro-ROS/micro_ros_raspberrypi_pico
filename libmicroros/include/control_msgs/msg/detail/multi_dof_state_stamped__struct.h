// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_msgs:msg/MultiDOFStateStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "control_msgs/msg/multi_dof_state_stamped.h"


#ifndef CONTROL_MSGS__MSG__DETAIL__MULTI_DOF_STATE_STAMPED__STRUCT_H_
#define CONTROL_MSGS__MSG__DETAIL__MULTI_DOF_STATE_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'dof_states'
#include "control_msgs/msg/detail/single_dof_state__struct.h"

/// Struct defined in msg/MultiDOFStateStamped in the package control_msgs.
/**
  * This message presents current controller state of multiple degrees of freedom.
 */
typedef struct control_msgs__msg__MultiDOFStateStamped
{
  /// Header timestamp should be update time of controller state
  std_msgs__msg__Header header;
  control_msgs__msg__SingleDOFState__Sequence dof_states;
} control_msgs__msg__MultiDOFStateStamped;

// Struct for a sequence of control_msgs__msg__MultiDOFStateStamped.
typedef struct control_msgs__msg__MultiDOFStateStamped__Sequence
{
  control_msgs__msg__MultiDOFStateStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__msg__MultiDOFStateStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_MSGS__MSG__DETAIL__MULTI_DOF_STATE_STAMPED__STRUCT_H_
