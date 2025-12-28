#pragma once
//! i guess the basic componets i need for now are just
// transform, camera, object(?), movement, collider(?)
//
// and i can just add more inside the project as needed
// its just a voxel engine how bad could this get? /s

#define ecs_register(_id, _C, _ecs, _system)                                   \
  _ecs_register_internal((_id), sizeof(_C), (_ecs), (_system))
#include "Context.h"
#include "Entity.h"
#include "Util/Bitvec.h"
#include "Util/Id.h"
#include "Util/Types.h"
#include <stdint.h>
#include <stdio.h>

typedef uint64_t ECStag;

enum ECSEvent { ECS_INIT = 0, ECS_UPDATE, ECS_TICK, ECS_RENDER, ECS_DESTROY };
typedef void (*ECSSubscriber)(void *, Entity);
union ECSSystem {
  struct {
    ECSSubscriber init, update, tick, render, destroy;
  };
  // ECSSubscriber subscribers[ECSEVENT_LAST + 1];
};
typedef struct {
  union ECSSystem system;
  void *components;
  size_t component_size;
} ComponentList;

enum ECSTagValues { ECS_TAG_USED = 1 << 0 };

typedef struct {
  // ComponentList lists[ECSCOMPONENT_LAST + 1];
  Id *ids;
  Bitvec used;
  size_t capacity;
  Id next_entity_id;
} ECS;
void _ecs_register_internal(enum ECSComponent id, size_t component_size,
                            struct ECS *ecs, union ECSSystem system);

void _ecs_add_internal(struct Entity entity, enum ECSComponent component_id,
                       void *value);

#define _ecs_add3(e, c, v)                                                     \
  ({                                                                           \
    __typeof__(v) _v = (v);                                                    \
    _ecs_add_internal((e), (c), &_v);                                          \
  })
#define _ecs_add2(e, c) _ecs_add_internal((e), (c), NULL)

#define _ecs_add_overload(_1, _2, _3, NAME, ...) NAME
#define ecs_add(...)                                                           \
  _ecs_add_overload(__VA_ARGS__, _ecs_add3, _ecs_add2)(__VA_ARGS__)

void ecs_event(struct ECS *self, enum ECSEvent event);
struct Entity ecs_new(struct ECS *self);
void ecs_delete(struct ECS *self, struct Entity entity);
void ecs_remove(struct Entity entity, enum ECSComponent component);
bool ecs_has(struct Entity entity, enum ECSComponent component);
void *ecs_get(struct Entity entity, enum ECSComponent component);
void ecs_init(struct ECS *self, Context *context);
void ecs_destroy(struct ECS *self);
