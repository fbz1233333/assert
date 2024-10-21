cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform_sdl_project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_platform_sdl3 ${local_src} ${local_header})
target_link_libraries(fxcc_platform_sdl3 PRIVATE SDL3::SDL3 fxcc_platform_common)