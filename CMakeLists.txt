cmake_minimum_required(VERSION 3.20)
project(GruVe C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# --- 1. SETUP GLAD CORRECTLY ---
# Create the library from the specific source file
add_library(glad STATIC Extern/Include/glad.c)

# Add the INCLUDE directory to the glad target. 
# Using CMAKE_CURRENT_SOURCE_DIR ensures the path is absolute and correct.
target_include_directories(glad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Extern/Include")

set(OpenGL_GL_PREFERENCE GLVND)

# --- 2. SETUP GRUVE ---
# Only GLOB your Core files. Do NOT GLOB the Extern folder anymore.
file(GLOB_RECURSE CORE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Core/*.c")

add_library(GruVe STATIC)

# Only add CORE sources. We link glad effectively as a library below.
target_sources(GruVe PRIVATE ${CORE})

# We don't need to manually add Extern/Include here anymore.
# Because we link 'glad' (which is PUBLIC), GruVe inherits the include path automatically.
target_include_directories(GruVe PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Core" 
    ${GLFW_INCLUDE_DIRS}
)

# Link glad. This pulls in the glad code AND the include path (Extern/Include).
target_link_libraries(GruVe PUBLIC glad ${GLFW_LIBRARIES} OpenGL::GL ${CMAKE_DL_LIBS} m)

# Debug Lib Tester
add_executable(GruVeTest Debug/main.c)

target_link_libraries(GruVeTest PRIVATE GruVe)
target_include_directories(GruVeTest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Core")

