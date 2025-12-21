#pragma once

// a scene stores the current runtime data, i.e meshes, entities, ect
#include "Archetypes/Component.h"
#include "Archetypes/Entities/UUID.h"
#include "Archetypes/Entity.h"
#include "Helpers/Hashtable.h"
#include <stddef.h>
#include <stdint.h>

#define MAX_ENTITIES 10000

typedef struct {
  const char *name;
  UUid id;
  Entity entities[MAX_ENTITIES];
  Hashtable components;
  uint32_t componentCount;
  uint32_t entityCount;

} Scene;

int AddEntityToScene(Scene *scene);
void AddComponentToEntity(Scene *scene, UUid entityId, uint8_t componentId);

UUid RegisterComponentToScene(Scene *scene, const char *name, void *data,
                              size_t size);
