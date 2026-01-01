#pragma once

#include "layers.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
typedef struct {

  GLFWwindow *application_window;
  struct layer_stack *layer_stack;
  int window_width;
  int window_height;
} Application;

int InitApp();
int CreateWindow(int wsize, int hsize, const char *wtitle, Application *wapp);
int InitGlad();
int ApplicationLoop(Application *wapp);

// global application
void Setup(Application *SetupApp, int wsize, int hsize, const char *wtitle);
