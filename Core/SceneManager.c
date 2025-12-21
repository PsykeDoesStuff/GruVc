#include "SceneManager.h"
#include "Archetypes/Entities/UUID.h"
#include "Helpers/Hashtable.h"
#include <stdio.h>

UUid CreateScene(SceneManager *root, const char *name) {
  Scene scene;
  GenerateUUid(&scene.id);
  HashTableInit(&scene.components);
  scene.name = name;
  scene.componentCount = 0;
  scene.entityCount = 0;
  

  char *uuid = UUidToString(32, scene.id);

  HashtableSet(&root->Scenes, uuid, (char *)&scene, sizeof(scene));
  return scene.id;
}
