cmake_minimum_required (VERSION 2.6)

project(math)

find_package(PhysX)
if(${PHYSX_LIBRARIES})
	add_definitions(-DPHYSX)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DEBUG -g -std=c++0x -Wall -Werror -Wno-unused-local-typedefs -Wno-unknown-pragmas -rdynamic -pthread")

add_definitions(-DTINYXML)

# common methods for static library
# =================================
include($ENV{HOME}/usr/lib/cmake/CMakeHelper/static_library.cmake)

#add_subdirectory(test)


