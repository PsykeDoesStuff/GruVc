#include "UUID.h"
#include <GLFW/glfw3.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void GenerateUUid(UUid *id) {
  // 1. Static counter ensures uniqueness if called twice in the same frame
  static uint64_t counter = 0;
  counter++;

  // 2. Get time as a high-precision integer (not just seconds)
  // multiplying by 1,000,000 gives us microseconds
  uint64_t time = (uint64_t)(glfwGetTime() * 1000000.0);

  // 3. Combine them (Time + Counter) so the input is unique
  uint64_t input = time + counter;

  // 4. Run the Hash (MurmurHash3 Mixer)
  input ^= input >> 33;
  input *= 0xff51afd7ed558ccdULL;
  input ^= input >> 33;
  input *= 0xc4ceb9fe1a85ec53ULL;
  input ^= input >> 33;

  *id = input;
}
char *UUidToString(size_t length, UUid id) {

  char *uuidstr = malloc(length);
  if (uuidstr != NULL) {
    snprintf(uuidstr, sizeof(uuidstr), "%llu", (unsigned long long)id);
    return uuidstr;
  }
  return NULL;
}
