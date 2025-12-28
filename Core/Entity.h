#pragma once
#include "Util/Id.h"
#include <stdint.h>
#define ENTITY_NONE 0

typedef struct {
  Id id;
  uint64_t index;
} Entity;
