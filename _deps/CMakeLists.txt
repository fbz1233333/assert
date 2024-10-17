cmake_minimum_required(VERSION 3.5.0)

project(_deps)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_SHARED_LIBRARY_SUFFIX "")

add_subdirectory(assimp)
add_subdirectory(Entt)
add_subdirectory(freetype)
add_subdirectory(openal-soft)

# add_subdirectory(imgui)
add_subdirectory(imnodes)
add_subdirectory(freetype)
add_subdirectory(glfw)
add_subdirectory(imnodes)
add_subdirectory(yaml-cpp)
add_subdirectory(reactphysics)