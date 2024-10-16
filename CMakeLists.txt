cmake_minimum_required(VERSION 3.5.0)
project(fxcc_project)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    stb
    GIT_REPOSITORY git@gitee.com:ddaren/stb.git
    GIT_TAG master
)


FetchContent_Declare(
    imgui
    GIT_REPOSITORY git@gitee.com:hang-jingqi/imgui.git
    GIT_TAG docking
)

FetchContent_Declare(
    assimp
    GIT_REPOSITORY git@gitee.com:github-transport/assimp.git
    GIT_TAG master
)


FetchContent_Declare(
    glm
    GIT_REPOSITORY git@gitee.com:ren-maolin/glm.git
    GIT_TAG master
)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY git@gitee.com:shuitailiangyue/glfw.git
    GIT_TAG master
)


FetchContent_Populate(imgui)
FetchContent_Populate(stb)
FetchContent_MakeAvailable(assimp)
FetchContent_MakeAvailable(glfw)
FetchContent_Populate(glm)


include_directories(${stb_SOURCE_DIR})
include_directories(${imgui_SOURCE_DIR})
include_directories(${imgui_SOURCE_DIR}/backends)
include_directories(${assimp_SOURCE_DIR}/include)
include_directories(${assimp_BINARY_DIR}/include)
include_directories(${glm_SOURCE_DIR})
include_directories(${glfw_SOURCE_DIR}/include)

if(WIN32)
set(FXCC_BUILD_GRAPH_OPENGL3 ON)
endif()

if(UNIX)
set(FXCC_BUILD_GRAPH_GLES3 ON)
endif()
# set(FXCC_BUILD_AUDIO_OPENAL ON)
# set(FXCC_BUILD_PHYSICS_RP3D ON)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)