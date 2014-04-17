cmake_minimum_required (VERSION 2.6)
#include(ExternalProject)

project(math)

set(LIB_NAME math)
set(PROJECT_NAME MATH)
set(PROJECT_name math)

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

set(INSTALL_LIB_DIR ${CMAKE_INSTALL_PREFIX})
set(INSTALL_BIN_DIR ${CMAKE_INSTALL_PREFIX})
set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/math)
set(INSTALL_CMAKE_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME})


# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
	set(var INSTALL_${p}_DIR)
	if(NOT IS_ABSOLUTE "${${var}}")
		set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()







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

# Source Files
# ============

file(GLOB_RECURSE SOURCES_ABS ${PROJECT_SOURCE_DIR}/*.cpp)
foreach(s ${SOURCES_ABS})
	#MESSAGE("${s} ${CMAKE_SOURCE_DIR}${PROJECT_SOURCE_DIR}")	
	file(RELATIVE_PATH s ${CMAKE_SOURCE_DIR} ${s})
	set(SOURCES ${SOURCES} ${s})
endforeach()
#MESSAGE("${SOURCES}")


file(GLOB_RECURSE HEADERS_ABS ${PROJECT_SOURCE_DIR}/*.hpp)
foreach(s ${HEADERS_ABS})
	#MESSAGE("${s} ${CMAKE_SOURCE_DIR}${PROJECT_SOURCE_DIR}")	
	file(RELATIVE_PATH s ${CMAKE_SOURCE_DIR}/${PROJECT_SOURCE_DIR} ${s})
	set(HEADERS ${HEADERS} ${s})
endforeach()
#MESSAGE("${HEADERS}")


add_library(math ${SOURCES})

configure_file("${PROJECT_SOURCE_DIR}/math/config.hpp.in" "${PROJECT_SOURCE_DIR}/math/configpp.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DEBUG -g -std=c++0x -Wall -Werror -Wno-unused-local-typedefs -Wno-unknown-pragmas -rdynamic -pthread")



#MESSAGE("${INSTALL_LIB_DIR}")
#MESSAGE("${INSTALL_BIN_DIR}")
#MESSAGE("${INSTALL_INCLUDE_DIR}")
#MESSAGE("${INSTALL_CMAKE_DIR}")

install(
	TARGETS math
	DESTINATION "${INSTALL_LIB_DIR}"
	EXPORT ${PROJECT_name}Targets
	RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
	LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
	PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/math" COMPONENT dev
)

foreach(h ${HEADERS})
	get_filename_component(f ${h} PATH)
	#MESSAGE("${h} ${f}")
	install(FILES ${PROJECT_SOURCE_DIR}/${h} DESTINATION include/${f})
endforeach()

#install(FILES ${PROJECT_SOURCE_DIR}/math/config.h	DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/math.h		DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/free.h		DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/vecbase.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/vec2.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/vec3.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/vec4.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/mat33.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/mat44.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/plane.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/color.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/quat.h DESTINATION		include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/transform.h DESTINATION	include/math/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/geo/polyhedron.h DESTINATION	include/math/geo/)
#install(FILES ${PROJECT_SOURCE_DIR}/math/vclip/vclip.h DESTINATION	include/math/vclip)




#project(test_array)
#add_executable(test_array test/array/main.cpp)
#target_link_libraries(test_array math)



# The interesting stuff goes here
# ===============================

# Add all targets to the build-tree export set

#export(TARGETS ${LIB_NAME} FILE "${PROJECT_BINARY_DIR}/${PROJECT_name}Targets.cmake")
export(TARGETS ${LIB_NAME} FILE "${INSTALL_BIN_DIR}/${PROJECT_name}Targets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE ${PROJECT_NAME})

# Create the FooBarConfig.cmake and FooBarConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")

# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(
	${PROJECT_name}Config.cmake.in
	"${PROJECT_BINARY_DIR}/${PROJECT_name}Config.cmake"
	@ONLY)

# ... for the install tree
set(CONF_INCLUDE_DIRS "\${FOOBAR_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(
	${PROJECT_name}Config.cmake.in
	"${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_name}Config.cmake"
	@ONLY)

# ... for both
configure_file(
	${PROJECT_name}ConfigVersion.cmake.in
	"${PROJECT_BINARY_DIR}/${PROJECT_name}ConfigVersion.cmake"
	@ONLY)

# Install the FooBarConfig.cmake and FooBarConfigVersion.cmake
install(FILES
	"${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_name}Config.cmake"
	"${PROJECT_BINARY_DIR}/${PROJECT_name}ConfigVersion.cmake"
	DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
#MESSAGE("${INSTALL_CMAKE_DIR}")

install(
	EXPORT ${PROJECT_name}Targets
	DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)



