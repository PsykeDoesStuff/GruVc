#pragma once

#include <GLFW/glfw3.h>
#include <stdio.h>

typedef struct {

  GLFWwindow *ApplicationWindow;
  int WindowWidth;
  int WindowHeight;

} Application;

int InitApp();
int CreateWindow(int wsize, int hsize, const char *wtitle, Application *wapp);
int InitGlad();
int ApplicationLoop(Application *wapp);

// global application
void Setup(Application *SetupApp, int wsize, int hsize, const char *wtitle);
