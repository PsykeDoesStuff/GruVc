#pragma once
#include "Archetypes/Entities/UUID.h"
#include <stdio.h>
// macro file

#define CLASS(Name)                                                            \
  typedef struct Name Name;                                                    \
  typedef struct Name##VTable Name##VTable;                                    \
  struct Name {                                                                \
    Name##VTable *vptr;                                                        \
  };
#define UUID_CLASS(Name)                                                       \
  typedef struct Name Name;                                                    \
  typedef struct Name##VTable Name##VTable;                                    \
  struct Name {                                                                \
    Name##VTable *vptr;                                                        \
    UUid id;                                                                   \
  };

#define CLASS_EXTENDS(Derrived, Base)                                          \
  typedef struct Derrived Derrived;                                            \
  struct Derrived {                                                            \
    Base super;

#define END_CLASS                                                              \
  }                                                                            \
  ;

#define CALL(obj, method, ...) (obj)->vptr->method((obj), ##__VA_ARGS__)

// example
/*

#define CLASS_METHODS void (*method_one)(void *self);

CLASS(exampleClass)
struct exampleClassVTable {
  CLASS_METHODS
};

CLASS_EXTENDS(exampleInheritor, exampleClass)
int var1;
float var2;
END_CLASS

void exampleInheritor_method_one(void *self) {
  exampleInheritor *ei = (exampleInheritor *)self;
  ei->var1++;
}

// define derrived vtable
exampleClassVTable inheritorVTable = {.method_one =
                                          exampleInheritor_method_one};
void exampleInheritor_init(exampleInheritor *ei, int x) 
  ei->super.vptr = &inheritorVTable;
}

*/
