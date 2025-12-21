#include "Scene.h"
#include "Archetypes/Entities/UUID.h"
#include "Archetypes/Entity.h"
#include "Helpers/Hashtable.h"
//self explanitory
int AddEntityToScene(Scene *scene) {
  scene->entities[scene->entityCount];
  scene->entityCount++;
  return scene->entityCount;
}
void AddComponentToEntity(Scene *scene, UUid entityId, uint8_t componentId){
  
}
//return component id for future use
UUid RegisterComponentToScene(Scene *scene, const char *name, void *data,
                              size_t size) {
  UUid id = 0;
  GenerateUUid(&id);
  char *strId = UUidToString(32, id);
  HashtableSet(&scene->components, strId, data, sizeof(data));
  scene->componentCount++;
  scene->registeredComponents[scene->componentCount] = id;
  return id;
}
