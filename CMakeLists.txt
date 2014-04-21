cmake_minimum_required (VERSION 2.6)

project(math)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DEBUG -g -std=c++0x -Wall -Werror -Wno-unused-local-typedefs -Wno-unknown-pragmas -rdynamic -pthread")

add_definitions(-DPHYSX -DTINYXML)

# common methods for static library
# =================================
include(../cmake/static_library.cmake)

#project(test_array)
#add_executable(test_array test/array/main.cpp)
#target_link_libraries(test_array math)



