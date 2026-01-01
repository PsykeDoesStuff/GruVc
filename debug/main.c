#include "application.h"

Application g_app;
int main() {

  Setup(&g_app, 800, 600, "Debug Test App");
  ApplicationLoop(&g_app);
}
