// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_msgs:msg/SingleDOFState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__SINGLE_DOF_STATE__STRUCT_H_
#define CONTROL_MSGS__MSG__DETAIL__SINGLE_DOF_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SingleDOFState in the package control_msgs.
/**
  * This message presents current controller state of one degree of freedom.
 */
typedef struct control_msgs__msg__SingleDOFState
{
  /// DoF name, e.g., joint or Cartesian axis name
  rosidl_runtime_c__String name;
  /// The set point, that is, desired state.
  double reference;
  /// Current value of the process (ie: latest sensor measurement on the controlled value).
  double feedback;
  /// First time-derivative of the process value. E.g., velocity.
  double feedback_dot;
  /// The error of the controlled value, essentially process_value - set_point (for a regular PID implementation).
  double error;
  /// First time-derivative of the error of the controlled value.
  double error_dot;
  /// Time between two consecutive updates/execution of the control law.
  double time_step;
  /// Current output of the controller.
  double output;
} control_msgs__msg__SingleDOFState;

// Struct for a sequence of control_msgs__msg__SingleDOFState.
typedef struct control_msgs__msg__SingleDOFState__Sequence
{
  control_msgs__msg__SingleDOFState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_msgs__msg__SingleDOFState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_MSGS__MSG__DETAIL__SINGLE_DOF_STATE__STRUCT_H_
