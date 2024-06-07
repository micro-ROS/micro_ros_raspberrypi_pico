// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_msgs:msg/MultiDOFCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "control_msgs/msg/multi_dof_command.h"


#ifndef CONTROL_MSGS__MSG__DETAIL__MULTI_DOF_COMMAND__STRUCT_H_
#define CONTROL_MSGS__MSG__DETAIL__MULTI_DOF_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'dof_names'
#include "rosidl_runtime_c/string.h"
// Member 'values'
// Member 'values_dot'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MultiDOFCommand in the package control_msgs.
/**
  * The message defines command for multiple degrees of freedom (DoF) typically used by many controllers.
  * The message intentionally avoids 'joint' nomenclature because it can be generally use for command with
  * different semantic meanings, e.g., joints, Cartesian axes, or have abstract meaning like GPIO interface.
 */
typedef struct control_msgs__msg__MultiDOFCommand
{
  /// names of degrees of freedom
  rosidl_runtime_c__String__Sequence dof_names;
  /// values used by most of the controller
  rosidl_runtime_c__double__Sequence values;
  /// First derivation of the values, e.g., velocity if values are positions.
  /// This is useful for PID and similar controllers.
  rosidl_runtime_c__double__Sequence values_dot;
} control_msgs__msg__MultiDOFCommand;

// Struct for a sequence of control_msgs__msg__MultiDOFCommand.
typedef struct control_msgs__msg__MultiDOFCommand__Sequence
{
  control_msgs__msg__MultiDOFCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__msg__MultiDOFCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_MSGS__MSG__DETAIL__MULTI_DOF_COMMAND__STRUCT_H_
