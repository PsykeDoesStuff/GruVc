#pragma once
#include "Entity.h"
#include "Util/Id.h"

typedef struct {
  Id scene_id;
} Scene;

Id GetSceneId(Scene *sceneToGet) { return sceneToGet->scene_id; }

// basic scene functions
void scene_awake(Scene *self);
void scene_update(Scene *self);
void scene_destroy(Scene *self);
void scene_tick(Scene *self);

// ecs
void scene_add_entity(Scene *self, Entity *entity);
void scene_remove_entity(Scene *self, Id entitty_to_remove);
