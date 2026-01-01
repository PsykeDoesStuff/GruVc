#include "layers.h"
#include <stdio.h>

void layer_stack_init(struct layer_stack *ls) {
  render_layer_start(&ls->l_renderer);
  ui_render_layer_start(&ls->l_ui_renderer);
  debug_layer_start(&ls->l_debug);
  runtime_layer_start(&ls->l_runtime);
  printf("init");
}
void layer_stack_update(struct layer_stack *ls) {
  render_layer_update(&ls->l_renderer);
  ui_render_layer_update(&ls->l_ui_renderer);
  debug_layer_update(&ls->l_debug);
  runtime_layer_update(&ls->l_runtime);

  printf("update");
}
void layer_stack_shutdown(struct layer_stack *ls) {
  render_layer_shutdown(&ls->l_renderer);
  ui_render_layer_shutdown(&ls->l_ui_renderer);
  debug_layer_shutdown(&ls->l_debug);
  runtime_layer_shutdown(&ls->l_runtime);
  printf("shutdown");
}

void render_layer_start(struct render_layer *) {}
void render_layer_update(struct render_layer *) {}
void render_layer_shutdown(struct render_layer *) {}

void render_layer_on_event(struct render_layer *, struct event *) {}
//---------------------------------------------
void ui_render_layer_start(struct ui_render_layer *) {}
void ui_render_layer_update(struct ui_render_layer *) {}
void ui_render_layer_shutdown(struct ui_render_layer *) {}

void ui_render_layer_on_event(struct ui_render_layer *, struct event *) {}

//---------------------------------------------
void debug_layer_start(struct debug_layer *) {}
void debug_layer_update(struct debug_layer *) {}
void debug_layer_shutdown(struct debug_layer *) {}

void debug_layer_on_event(struct debug_layer *, struct event *) {}

//---------------------------------------------
void runtime_layer_start(struct runtime_layer *) {}
void runtime_layer_update(struct runtime_layer *) {}
void runtime_layer_shutdown(struct runtime_layer *) {}

void runtime_layer_on_event(struct runtime_layer *, struct event *) {}
