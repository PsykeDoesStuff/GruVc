#pragma once

// Chunk theory:
// Chunks store a flat byte arry, if a block is solid (not air) its represented
// by a 1.
//  if the block at [i] is solid, we add it to the list of voxels to draw, else
//  we skip over it.

#define CHUNK_SIZE 10
#define CHUNK_DATA_SIZE (CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE)

#include <stdint.h>
typedef struct {
  uint8_t size;
  char blockData[CHUNK_DATA_SIZE];
} Chunk;

void DEBUG_CreateFullChunk(Chunk *chunk) {
  for (int i = 0; i < CHUNK_DATA_SIZE; i++) {
    chunk->blockData[i] = 1;
  }
}
