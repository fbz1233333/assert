cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform_glfw_project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_platform_glfw STATIC ${local_src} ${local_header})

target_link_libraries(fxcc_platform_glfw PUBLIC glfw3 )

if(UNIX)
target_link_libraries(fxcc_platform_glfw PUBLIC pthread dl)
endif()


if(WIN32)
target_link_libraries(fxcc_platform_glfw PUBLIC legacy_stdio_definitions.lib)
endif()