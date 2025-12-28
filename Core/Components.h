#pragma once

#define _ECS_DEF_COMPONENT(_name)                                              \
  extern void _name##_init();                                                  \
  _name##_init(ecs);

static inline void _ecs_init_internal(ECS *ecs) {
  // init internaL Components here
}

#define ECS_COMPONENT_LAST // last component here

enum ECSComponent { C_POSITION = 0, C_CAMERA, C_CONTROL, C_MOVEMENT, C_DEBUG };
