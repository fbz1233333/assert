cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform_common_project)

set(CMAKE_CXX_STANDARD 17)


file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_platform_common  ${local_src} ${local_header})
