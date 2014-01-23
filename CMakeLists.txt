cmake_minimum_required (VERSION 2.6)
include(ExternalProject)

project(nebula)

set(PROJECT_SOURCE_DIR src)

include_directories("${PROJECT_SOURCE_DIR}")

add_library(math
	src/math/free.cpp
	src/math/vec2.cpp
	src/math/vec3.cpp
	src/math/vec4.cpp
	src/math/mat33.cpp
	src/math/mat44.cpp
	src/math/plane.cpp
	src/math/color.cpp
	src/math/quat.cpp
	src/math/transform.cpp
	src/math/raw/raw.cpp
	src/math/geo/polyhedron.cpp
	src/math/vclip/vclip.cpp
)

configure_file("${PROJECT_SOURCE_DIR}/math/config.h.in" "${PROJECT_SOURCE_DIR}/math/config.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DEBUG -std=c++0x -Wall -Werror -Wno-unknown-pragmas -rdynamic -pthread")
set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

install(TARGETS math DESTINATION lib)

install(FILES ${PROJECT_SOURCE_DIR}/math/config.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/math.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/free.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vec2.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vec3.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vec4.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/mat33.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/mat44.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/plane.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/color.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/quat.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/transform.h DESTINATION	include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/raw/raw.h DESTINATION		include/math/raw)
install(FILES ${PROJECT_SOURCE_DIR}/math/geo/polyhedron.h DESTINATION	include/math/geo/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vclip/vclip.h DESTINATION	include/math/vclip)



