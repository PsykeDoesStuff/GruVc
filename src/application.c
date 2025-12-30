#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
// order
#include "application.h"
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int InitApp() {
  glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  return 0;
}

int InitGlad() {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("failed to initialize glad\n");
    return -1;
  }
  return 0;
}

void FrameBufferSizeCallback(GLFWwindow *window, int width, int height) {

  glViewport(0, 0, width, height);
}

int SetWindowIcon(Application *app, const char *iconPath) {
  GLFWimage icon[1];
  int channels;

  icon[0].pixels =
      stbi_load(iconPath, &icon[0].width, &icon[0].height, &channels, 4);

  if (icon[0].pixels) {
    glfwSetWindowIcon(app->ApplicationWindow, 1, icon);
    stbi_image_free(icon[0].pixels);
    printf("loaded image at %s\n", iconPath);
    return 0;
  } else {
    printf("failed to load app icon at: %s\n", iconPath);
  }
  return -1;
}

int CreateWindow(int wsize, int hsize, const char *wtitle, Application *wapp) {
  wapp->WindowHeight = hsize;
  wapp->WindowHeight = wsize;
  wapp->ApplicationWindow = glfwCreateWindow(wsize, hsize, wtitle, NULL, NULL);

  if (wapp->ApplicationWindow == NULL) {
    printf("Failed to create Window\n");
    glfwTerminate();
    return -1;
  }

  SetWindowIcon(wapp, "resources/icon.png");

  glfwMakeContextCurrent(wapp->ApplicationWindow);
  glfwSetFramebufferSizeCallback(wapp->ApplicationWindow,
                                 FrameBufferSizeCallback);

  return 0;
}
int ApplicationLoop(Application *wapp) {

  while (!glfwWindowShouldClose(wapp->ApplicationWindow)) {
    glfwSwapBuffers(wapp->ApplicationWindow);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
void Setup(Application *SetupApp, int wsize, int hsize, const char *wtitle) {
  InitApp();
  CreateWindow(wsize, hsize, wtitle, SetupApp);
  InitGlad();
}
