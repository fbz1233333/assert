cmake_minimum_required(VERSION 3.5.0)

project(fxcc_physics)

set(CMAKE_CXX_STANDARD 17)

if(FXCC_BUILD_PHYSICS_PHYSX)
add_subdirectory(physX)
endif()

if(FXCC_BUILD_PHYSICS_BULLET3D)
add_subdirectory(bullet3d)
endif()

if(FXCC_BUILD_PHYSICS_RP3D)
add_subdirectory(rp3d)
endif()
