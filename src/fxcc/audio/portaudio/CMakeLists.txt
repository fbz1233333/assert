cmake_minimum_required(VERSION 3.5.0)

project(fxcc_audio_portaudio)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_headers *.h)

add_library(fxcc_audio_portaudio ${local_headers} ${local_src})
