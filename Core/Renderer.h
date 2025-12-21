#pragma once

typedef enum { API_OPENGL, API_VULKAN } RENDERING_API_FLAG;

typedef struct {
  RENDERING_API_FLAG g_RenderingApi;
} Renderer;
