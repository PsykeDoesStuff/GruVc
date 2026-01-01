#pragma once
#include "util/types.h"
struct event {
  c_bool consumed; // set to false by def
  void *event_data;
};

static inline void event_consume(struct event *ev) { ev->consumed = TRUE; }
static inline c_bool event_is_consumed(struct event *ev) {
  return ev->consumed;
}
