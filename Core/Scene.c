#include "Scene.h"
#include "Archetypes/Entities/UUID.h"
#include "Archetypes/Entity.h"
#include "Helpers/Hashtable.h"

int AddEntityToScene(Scene *scene) {
  scene->entities[scene->entityCount];
  scene->entityCount++;
  return scene->entityCount;
}
UUid RegisterComponentToScene(Scene *scene, const char *name, void *data,
                              size_t size) {
  UUid id = 0;
  GenerateUUid(&id);
  char *strId = UUidToString(32, id);
  HashtableSet(&scene->components, strId, data, sizeof(data));

  scene->componentCount++;
  return id;
}
