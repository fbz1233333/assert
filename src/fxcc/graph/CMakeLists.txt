cmake_minimum_required(VERSION 3.15.0)

project(fxcc_graph_Project)


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

