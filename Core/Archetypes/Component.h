#pragma once

#include <stddef.h>
#include <stdint.h>

typedef uint64_t ComponentId;

typedef struct {
  char Name[32];
  size_t size;
  ComponentId id;
} ComponentTypeInfo;

ComponentId RegisterComponent(const char *name, size_t size);
