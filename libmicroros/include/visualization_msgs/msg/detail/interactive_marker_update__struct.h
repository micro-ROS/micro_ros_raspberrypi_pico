// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from visualization_msgs:msg/InteractiveMarkerUpdate.idl
// generated code does not contain a copyright notice

#ifndef VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_UPDATE__STRUCT_H_
#define VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_UPDATE__STRUCT_H_

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
#define visualization_msgs__msg__InteractiveMarkerUpdate__TYPE_VERSION_HASH__INIT {1, { \
      0x88, 0xba, 0xb6, 0x13, 0xcb, 0x27, 0x0a, 0x62, \
      0xc3, 0x7a, 0x88, 0x13, 0x1f, 0x9a, 0x0d, 0xbd, \
      0x9b, 0x28, 0x66, 0x53, 0xb2, 0x3e, 0xc4, 0x2a, \
      0x2d, 0xed, 0xb8, 0x1f, 0x97, 0xb5, 0x2b, 0x0d, \
    }}
static const rosidl_type_hash_t visualization_msgs__msg__InteractiveMarkerUpdate__TYPE_VERSION_HASH = visualization_msgs__msg__InteractiveMarkerUpdate__TYPE_VERSION_HASH__INIT;

// Constants defined in the message

/// Constant 'KEEP_ALIVE'.
/**
  * Type holds the purpose of this message.  It must be one of UPDATE or KEEP_ALIVE.
  * UPDATE: Incremental update to previous state.
  *         The sequence number must be 1 higher than for
  *         the previous update.
  * KEEP_ALIVE: Indicates the that the server is still living.
  *             The sequence number does not increase.
  *             No payload data should be filled out (markers, poses, or erases).
 */
enum
{
  visualization_msgs__msg__InteractiveMarkerUpdate__KEEP_ALIVE = 0
};

/// Constant 'UPDATE'.
enum
{
  visualization_msgs__msg__InteractiveMarkerUpdate__UPDATE = 1
};

// Include directives for member types
// Member 'server_id'
// Member 'erases'
#include "rosidl_runtime_c/string.h"
// Member 'markers'
#include "visualization_msgs/msg/detail/interactive_marker__struct.h"
// Member 'poses'
#include "visualization_msgs/msg/detail/interactive_marker_pose__struct.h"

/// Struct defined in msg/InteractiveMarkerUpdate in the package visualization_msgs.
typedef struct visualization_msgs__msg__InteractiveMarkerUpdate
{
  /// Identifying string. Must be unique in the topic namespace
  /// that this server works on.
  rosidl_runtime_c__String server_id;
  /// Sequence number.
  /// The client will use this to detect if it has missed an update.
  uint64_t seq_num;
  uint8_t type;
  /// Note: No guarantees on the order of processing.
  ///       Contents must be kept consistent by sender.
  /// Markers to be added or updated
  visualization_msgs__msg__InteractiveMarker__Sequence markers;
  /// Poses of markers that should be moved
  visualization_msgs__msg__InteractiveMarkerPose__Sequence poses;
  /// Names of markers to be erased
  rosidl_runtime_c__String__Sequence erases;
} visualization_msgs__msg__InteractiveMarkerUpdate;

// Struct for a sequence of visualization_msgs__msg__InteractiveMarkerUpdate.
typedef struct visualization_msgs__msg__InteractiveMarkerUpdate__Sequence
{
  visualization_msgs__msg__InteractiveMarkerUpdate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} visualization_msgs__msg__InteractiveMarkerUpdate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_UPDATE__STRUCT_H_
