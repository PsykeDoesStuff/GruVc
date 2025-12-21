#pragma once 
#include "../Component.h"
#include "../../Helpers/OOP.h"
#include <stdint.h>
// -------TRANSFORMS ------
CLASS_EXTENDS(FTransform, Component)
  float positions[3];
  //rotations  
  float scale[3];
  END_CLASS
CLASS_EXTENDS(ITransform, Component)
  short positions[3];
short scale;
  //cant really have rotations with ints, either way this is for the voxels not so much anything else
  END_CLASS

void ITransformSetPosition(ITransform* self, uint32_t new[3]){
  self->positions = new;
}
void FTransformSetPosition(FTransform* self, float new[3]){
  self->positions = new;
}
//fill out with methods later

ComponentVTable ITransformVTable = {}
ComponentVTable FTransformVTable = {}

void ITranform_init(ITransform*self){
  self->positions = {0,0,0};
  self->super = &ITransformVTable;
}

void FTranform_init(FTransform*self){
  self->positions = {0.0,0.0,0.0};
  self->scale = {1.0,1.0,1.0};
  self->super = &FTransformVTable;
}
void FTransformSetScale(FTransform*self,float newscale[3]){
  self->scale = newscale;
    }

void ITransformSetScale(ITransform*self,short newscale[3]){
  self->scale = newscale;
}
// -------TRANSFORMS ------

