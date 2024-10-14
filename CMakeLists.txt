cmake_minimum_required(VERSION 3.5.0)
project(fxcc_project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(fxcc)

# if(UNIX)
# set(DEP_PATH /usr/local)
# endif()

# set(CMAKE_INSTALL_INCLUDEDIR ${DEP_PATH}/include)
# set(CMAKE_INSTALL_LIBDIR ${DEP_PATH}/lib)

# install(TARGETS web
#         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )

# install(DIRECTORY include
#         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})



# add_subdirectory(test)
