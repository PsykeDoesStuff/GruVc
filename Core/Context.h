#pragma once

// the context is where everything *lives*
// in essence, the context is the world that holds all the entities and scenes
// inside, this way i can easily
// 1. display said project
// 2. transition between levels||enviroments easier

#include "Ecs.h"
#define MAX_SCENES_PER_CONTEXT 10 // because why would you need more than this??

#include "Scene.h"
#include "Util/Id.h"
#include <stdio.h>

typedef struct {

  Scene *context_scenes[MAX_SCENES_PER_CONTEXT];
  Id active_scene_id;
  ECS *ecs;
  u64 ticks;
} Context;

Scene *GetActiveContextScene(Context *context) {
  if (!context) {

    return NULL;
  }

  for (int i = 0; i < MAX_SCENES_PER_CONTEXT; ++i) {
    Scene *current_scene = context->context_scenes[i];

    // 1. Check if the slot is valid (not NULL)
    // 2. Check if the ID matches
    if (current_scene != NULL &&
        GetSceneId(current_scene) == context->active_scene_id) {

      return current_scene;
    }
  }

  return NULL;
}
// basic world functions
void context_init(Context *self);
void context_destroy(Context *self);
void context_render(Context *self);
void context_update(Context *self);
void context_tick(Context *self);
