cmake_minimum_required(VERSION 3.5.0)

project(fxcc_graph)

set(CMAKE_CXX_STANDARD 17)

file(GLOB local_src *.cpp)
file(GLOB local_header *.h)

add_library(fxcc_graph ${local_src} ${local_header})