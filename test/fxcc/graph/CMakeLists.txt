cmake_minimum_required(VERSION 3.5.0)

project(fxcc_test_platform)

set(CMAKE_CXX_STANDARD 17)

set(FXCC_PLATFORM_GLFW_SCLAE_FACTOR "1.5f")

add_executable(fxcc_test_glfw_opengl3 opengraph.cpp )
target_link_libraries(fxcc_test_glfw_opengl3 PUBLIC fxcc_platform_glfw fxcc_graph_opengl3)
target_compile_definitions(fxcc_test_win32_openwindow PRIVATE FXCC_USE_PLATFORM_GLFW FXCC_USE_PLATFORM_GLFW_OPENGL3)


