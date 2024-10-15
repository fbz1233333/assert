cmake_minimum_required(VERSION 3.5.0)

project(fxcc_project)

set(CMAKE_CXX_STANDARD 17)

if(FXCC_BUILD_AUDIO_OPENAL)
add_subdirectory(openal)
endif()

if(FXCC_BUILD_AUDIO_PORTAUDIO)
add_subdirectory(portaudio)
endif()