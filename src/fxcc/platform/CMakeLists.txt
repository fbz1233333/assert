cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(common)

if(FXCC_BUILD_PLATFORM_GLFW)
add_subdirectory(glfw)
endif()

if(FXCC_BUILD_PLATFORM_WIN32)
add_subdirectory(win32)
endif()


if(FXCC_BUILD_PLATFORM_SDL2)
add_subdirectory(sdl2)
endif()

if(FXCC_BUILD_PLATFORM_SDL3)
add_subdirectory(sdl3)
endif()
