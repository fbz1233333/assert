cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform_sdl_project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_platform_sdl3 ${local_src} ${local_header})

if(WIN32)
set(sdl3lib SDL3::SDL3 )
endif()
if(UNIX)
set(sdl3lib SDL3 )
endif()

target_link_libraries(fxcc_platform_sdl3 PRIVATE ${sdl3lib} fxcc_platform_common)