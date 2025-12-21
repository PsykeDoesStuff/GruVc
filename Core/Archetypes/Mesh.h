#pragma once

#include <stdint.h>
typedef uint32_t VertexData;

typedef struct {
  VertexData vertexData[];
} MeshComponent;

void SetVertexBitData(VertexData *vdata, int data[6]);
