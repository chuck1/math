cmake_minimum_required (VERSION 2.6)
include(ExternalProject)

project(math)

set(PROJECT_SOURCE_DIR src)

include_directories("${PROJECT_SOURCE_DIR}")

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
		${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
	add_custom_target(doc
		${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
endif(DOXYGEN_FOUND)



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
	src/math/geo/polyhedron.cpp
	src/math/vclip/vclip.cpp
)

configure_file("${PROJECT_SOURCE_DIR}/math/config.h.in" "${PROJECT_SOURCE_DIR}/math/config.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DEBUG -g -std=c++0x -Wall -Werror -Wno-unused-local-typedefs -Wno-unknown-pragmas -rdynamic -pthread")
set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

install(TARGETS math DESTINATION lib)

install(FILES ${PROJECT_SOURCE_DIR}/math/config.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/math.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/free.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vecbase.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vec2.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vec3.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vec4.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/mat33.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/mat44.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/plane.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/color.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/quat.h DESTINATION		include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/transform.h DESTINATION	include/math/)
install(FILES ${PROJECT_SOURCE_DIR}/math/geo/polyhedron.h DESTINATION	include/math/geo/)
install(FILES ${PROJECT_SOURCE_DIR}/math/vclip/vclip.h DESTINATION	include/math/vclip)


project(test_array)
add_executable(test_array test/array/main.cpp)
target_link_libraries(test_array math)

set(LIB_NAME math)
set(PROJECT_NAME math)

set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/math)
set(INSTALL_CMAKE_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME})

MESSAGE("${INSTALL_INCLUDE_DIR}")
MESSAGE("${INSTALL_CMAKE_DIR}")

# The interesting stuff goes here
# ===============================

# Add all targets to the build-tree export set
export(TARGETS ${LIB_NAME} FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE ${PROJECT_NAME})

# Create the FooBarConfig.cmake and FooBarConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")

# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(
	${PROJECT_NAME}Config.cmake.in
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	@ONLY)

# ... for the install tree
set(CONF_INCLUDE_DIRS "\${FOOBAR_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(
	${PROJECT_NAME}Config.cmake.in
	"${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}Config.cmake"
	@ONLY)

# ... for both
configure_file(FooBarConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/FooBarConfigVersion.cmake" @ONLY)

# Install the FooBarConfig.cmake and FooBarConfigVersion.cmake
install(FILES
	"${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/FooBarConfig.cmake"
	"${PROJECT_BINARY_DIR}/FooBarConfigVersion.cmake"
	DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT ${PROJECT_NAME}Targets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)



