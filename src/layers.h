#pragma once

#include "events.h"

struct render_layer {};
struct ui_render_layer {};
struct debug_layer {};
struct runtime_layer {};

struct layer_stack {
  struct render_layer l_renderer;
  struct ui_render_layer l_ui_renderer;
  struct debug_layer l_debug;
  struct runtime_layer l_runtime;
};
//-------------------------------------------
void render_layer_start(struct render_layer *);
void render_layer_update(struct render_layer *);
void render_layer_shutdown(struct render_layer *);

void render_layer_on_event(struct render_layer *, struct event *);
//---------------------------------------------
void ui_render_layer_start(struct ui_render_layer *);
void ui_render_layer_update(struct ui_render_layer *);
void ui_render_layer_shutdown(struct ui_render_layer *);

void ui_render_layer_on_event(struct ui_render_layer *, struct event *);

//---------------------------------------------
void debug_layer_start(struct debug_layer *);
void debug_layer_update(struct debug_layer *);
void debug_layer_shutdown(struct debug_layer *);

void debug_layer_on_event(struct debug_layer *, struct event *);

//---------------------------------------------
void runtime_layer_start(struct runtime_layer *);
void runtime_layer_update(struct runtime_layer *);
void runtime_layer_shutdown(struct runtime_layer *);

void runtime_layer_on_event(struct runtime_layer *, struct event *);
//---------------------------------------------
//
void layer_stack_init(struct layer_stack *);
void layer_stack_update(struct layer_stack *);
void layer_stack_shutdown(struct layer_stack *);
