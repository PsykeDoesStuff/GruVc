#pragma once

#include "Archetypes/Entities/UUID.h"
#include "Helpers/Hashtable.h"
#include "Scene.h"
typedef struct {
  Hashtable Scenes;
  UUid ActiveSceneId;
} SceneManager;

UUid CreateScene(SceneManager *root, const char *name);
void SetActiveScene(UUid id, SceneManager *manager);
UUid GetActiveSceneId(UUid id, SceneManager *manager);
Scene GetActiveScene(UUid id, SceneManager *manager);


