cmake_minimum_required(VERSION 3.5.0)

project(fxcc_project)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_SHARED_LIBS OFF)

if(WIN32)

add_subdirectory(_deps)
include_directories(${CMAKE_SOURCE_DIR}/_deps/glm)
include_directories(${CMAKE_SOURCE_DIR}/_deps/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/_deps/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/_deps/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/_deps/ztclog/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/_deps/SDL2/include)
include_directories(${CMAKE_SOURCE_DIR}/_deps/SDL3/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/SDL3/include)
link_directories(${CMAKE_SOURCE_DIR}/_deps/glfw/lib)
endif()

if(WIN32)
set(FXCC_BUILD_GRAPH_OPENGL3 ON)
endif()
set(FXCC_BUILD_GRAPH_DIRECTX11 ON)

set(FXCC_BUILD_PLATFORM_GLFW ON)

if(WIN32)
set(FXCC_BUILD_PLATFORM_WIN32 ON)
endif()

set(FXCC_BUILD_PLATFORM_SDL2 ON)
set(FXCC_BUILD_PLATFORM_SDL3 ON)


# set(FXCC_BUILD_AUDIO_OPENAL ON)
# set(FXCC_BUILD_PHYSICS_RP3D ON)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)
