cmake_minimum_required(VERSION 3.5.0)
project(fxcc_project)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

set(FXCC_BUILD_GRAPH_GLES3 ON)
# set(FXCC_BUILD_AUDIO_OPENAL ON)
# set(FXCC_BUILD_PHYSICS_RP3D ON)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)