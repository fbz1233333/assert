
cmake_minimum_required(VERSION 3.5.0)

project(fxcc_physics_rp3d_project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_headers *.h)

if(WIN32)
add_library(fxcc_graph_opengl3 ${local_headers} ${local_src} glad.c)
endif()

if(UNIX)
add_library(fxcc_graph_opengl3 ${local_headers} ${local_src} )
target_link_libraries(fxcc_graph_opengl3 PRIVATE GL)
endif()




