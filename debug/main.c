#include "application.h"

Application g_app;
int main() {

  Setup(&g_app, 800, 600, "Debug Test App");
  printf("Window Width: %d\n", &g_app.WindowWidth);
  ApplicationLoop(&g_app);
}
