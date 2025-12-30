cmake_minimum_required(VERSION 3.20)
project(GruVe C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

add_library(glad STATIC extern/include/glad.c)

target_include_directories(glad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/extern/include")

set(OpenGL_GL_PREFERENCE GLVND)

file(GLOB_RECURSE CORE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

add_library(GruVe STATIC)

target_sources(GruVe PRIVATE ${CORE})

target_include_directories(GruVe PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/src" 
    ${GLFW_INCLUDE_DIRS}
)

target_link_libraries(GruVe PUBLIC glad ${GLFW_LIBRARIES} OpenGL::GL ${CMAKE_DL_LIBS} m)

# Debug Lib Tester
add_executable(GruVeTest debug/main.c)

target_link_libraries(GruVeTest PRIVATE GruVe)
target_include_directories(GruVeTest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

