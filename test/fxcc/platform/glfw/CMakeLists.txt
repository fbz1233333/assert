cmake_minimum_required(VERSION 3.5.0)

project(fxcc_platform_test)

add_executable(openwindow openwindow.cpp )

target_link_libraries(openwindow PUBLIC fxcc_platform_glfw )
target_link_libraries(openwindow PUBLIC fxcc_platform_win32)
