#pragma once

#include "../Helpers/OOP.h"
#include "Entities/UUID.h"
#include <stddef.h>
#include <stdint.h>

#define COMPONENT_METHODS                                                      \
  void (*ComponentStart)(void *self);                                          \
  void (*ComponentUpdate)(void *self);                                         \
  void (*ComponentExit)(void *self);

UUID_CLASS(Component)
struct ComponentVTable {
  COMPONENT_METHODS
};
