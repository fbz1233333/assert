cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform_sdl2_project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_platform_sdl2 ${local_src} ${local_header})
if(WIN32)
set(sdl2lib SDL2::SDL2 )
endif()
if(UNIX)
set(sdl2lib SDL2 )
endif()
target_link_libraries(fxcc_platform_sdl2 PUBLIC ${sdl2lib} fxcc_platform_common)