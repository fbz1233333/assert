cmake_minimum_required(VERSION 3.5.0)

project(fxcc_graph_editor)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
    stb
    GIT_REPOSITORY git@gitee.com:ddaren/stb.git
    GIT_TAG master
)

FetchContent_Populate(stb)

include_directories(${stb_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY git@gitee.com:hang-jingqi/imgui.git
    GIT_TAG docking
)

FetchContent_Populate(imgui)
include_directories(${imgui_SOURCE_DIR})
include_directories(${imgui_SOURCE_DIR}/backends)

file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_graph ${local_src} ${local_header})

if(FXCC_BUILD_GRAPH_GLES)
add_subdirectory(gles)
endif()

if(FXCC_BUILD_GRAPH_GLES2)
add_subdirectory(gles2)
endif()

if(FXCC_BUILD_GRAPH_GLES3)
add_subdirectory(gles3)
endif()

if(FXCC_BUILD_GRAPH_OPENGL3)
add_subdirectory(opengl3)
endif()

if(FXCC_BULID_GFAPH_DIRECTX9)
add_subdirectory(directX9)
endif()

if(FXCC_BULID_GFAPH_DIRECTX11)
add_subdirectory(directX11)
endif()

if(FXCC_BULID_GFAPH_DIRECTX12)
add_subdirectory(directX12)
endif()

if(FXCC_BULID_GFAPH_VULKAN)
add_subdirectory(vulkan)
endif()

