#include "Mesh.h"

void SetVertexBitData(VertexData *vdata, int data[6]) {
  // reset data
  *vdata = 0;

  // x position
  *vdata |= data[0] & 0x3f;
  // y position
  *vdata |= (data[1] & 0x3f) << 6;
  // z position
  *vdata |= (data[2] & 0x3f) << 12;
  // normals
  *vdata |= (data[3] & 0x7) << 18;
}
