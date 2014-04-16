# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/charles/Programming/C++/math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charles/Programming/C++/math

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/charles/Programming/C++/math/CMakeFiles /home/charles/Programming/C++/math/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/charles/Programming/C++/math/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named doc

# Build rule for target.
doc: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 doc
.PHONY : doc

# fast build rule for target.
doc/fast:
	$(MAKE) -f CMakeFiles/doc.dir/build.make CMakeFiles/doc.dir/build
.PHONY : doc/fast

#=============================================================================
# Target rules for targets named math

# Build rule for target.
math: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 math
.PHONY : math

# fast build rule for target.
math/fast:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/build
.PHONY : math/fast

#=============================================================================
# Target rules for targets named test_array

# Build rule for target.
test_array: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_array
.PHONY : test_array

# fast build rule for target.
test_array/fast:
	$(MAKE) -f CMakeFiles/test_array.dir/build.make CMakeFiles/test_array.dir/build
.PHONY : test_array/fast

src/math/color.o: src/math/color.cpp.o
.PHONY : src/math/color.o

# target to build an object file
src/math/color.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/color.cpp.o
.PHONY : src/math/color.cpp.o

src/math/color.i: src/math/color.cpp.i
.PHONY : src/math/color.i

# target to preprocess a source file
src/math/color.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/color.cpp.i
.PHONY : src/math/color.cpp.i

src/math/color.s: src/math/color.cpp.s
.PHONY : src/math/color.s

# target to generate assembly for a file
src/math/color.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/color.cpp.s
.PHONY : src/math/color.cpp.s

src/math/free.o: src/math/free.cpp.o
.PHONY : src/math/free.o

# target to build an object file
src/math/free.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/free.cpp.o
.PHONY : src/math/free.cpp.o

src/math/free.i: src/math/free.cpp.i
.PHONY : src/math/free.i

# target to preprocess a source file
src/math/free.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/free.cpp.i
.PHONY : src/math/free.cpp.i

src/math/free.s: src/math/free.cpp.s
.PHONY : src/math/free.s

# target to generate assembly for a file
src/math/free.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/free.cpp.s
.PHONY : src/math/free.cpp.s

src/math/geo/polyhedron.o: src/math/geo/polyhedron.cpp.o
.PHONY : src/math/geo/polyhedron.o

# target to build an object file
src/math/geo/polyhedron.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o
.PHONY : src/math/geo/polyhedron.cpp.o

src/math/geo/polyhedron.i: src/math/geo/polyhedron.cpp.i
.PHONY : src/math/geo/polyhedron.i

# target to preprocess a source file
src/math/geo/polyhedron.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.i
.PHONY : src/math/geo/polyhedron.cpp.i

src/math/geo/polyhedron.s: src/math/geo/polyhedron.cpp.s
.PHONY : src/math/geo/polyhedron.s

# target to generate assembly for a file
src/math/geo/polyhedron.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.s
.PHONY : src/math/geo/polyhedron.cpp.s

src/math/mat33.o: src/math/mat33.cpp.o
.PHONY : src/math/mat33.o

# target to build an object file
src/math/mat33.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat33.cpp.o
.PHONY : src/math/mat33.cpp.o

src/math/mat33.i: src/math/mat33.cpp.i
.PHONY : src/math/mat33.i

# target to preprocess a source file
src/math/mat33.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat33.cpp.i
.PHONY : src/math/mat33.cpp.i

src/math/mat33.s: src/math/mat33.cpp.s
.PHONY : src/math/mat33.s

# target to generate assembly for a file
src/math/mat33.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat33.cpp.s
.PHONY : src/math/mat33.cpp.s

src/math/mat44.o: src/math/mat44.cpp.o
.PHONY : src/math/mat44.o

# target to build an object file
src/math/mat44.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat44.cpp.o
.PHONY : src/math/mat44.cpp.o

src/math/mat44.i: src/math/mat44.cpp.i
.PHONY : src/math/mat44.i

# target to preprocess a source file
src/math/mat44.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat44.cpp.i
.PHONY : src/math/mat44.cpp.i

src/math/mat44.s: src/math/mat44.cpp.s
.PHONY : src/math/mat44.s

# target to generate assembly for a file
src/math/mat44.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat44.cpp.s
.PHONY : src/math/mat44.cpp.s

src/math/plane.o: src/math/plane.cpp.o
.PHONY : src/math/plane.o

# target to build an object file
src/math/plane.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/plane.cpp.o
.PHONY : src/math/plane.cpp.o

src/math/plane.i: src/math/plane.cpp.i
.PHONY : src/math/plane.i

# target to preprocess a source file
src/math/plane.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/plane.cpp.i
.PHONY : src/math/plane.cpp.i

src/math/plane.s: src/math/plane.cpp.s
.PHONY : src/math/plane.s

# target to generate assembly for a file
src/math/plane.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/plane.cpp.s
.PHONY : src/math/plane.cpp.s

src/math/quat.o: src/math/quat.cpp.o
.PHONY : src/math/quat.o

# target to build an object file
src/math/quat.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/quat.cpp.o
.PHONY : src/math/quat.cpp.o

src/math/quat.i: src/math/quat.cpp.i
.PHONY : src/math/quat.i

# target to preprocess a source file
src/math/quat.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/quat.cpp.i
.PHONY : src/math/quat.cpp.i

src/math/quat.s: src/math/quat.cpp.s
.PHONY : src/math/quat.s

# target to generate assembly for a file
src/math/quat.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/quat.cpp.s
.PHONY : src/math/quat.cpp.s

src/math/transform.o: src/math/transform.cpp.o
.PHONY : src/math/transform.o

# target to build an object file
src/math/transform.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/transform.cpp.o
.PHONY : src/math/transform.cpp.o

src/math/transform.i: src/math/transform.cpp.i
.PHONY : src/math/transform.i

# target to preprocess a source file
src/math/transform.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/transform.cpp.i
.PHONY : src/math/transform.cpp.i

src/math/transform.s: src/math/transform.cpp.s
.PHONY : src/math/transform.s

# target to generate assembly for a file
src/math/transform.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/transform.cpp.s
.PHONY : src/math/transform.cpp.s

src/math/vclip/vclip.o: src/math/vclip/vclip.cpp.o
.PHONY : src/math/vclip/vclip.o

# target to build an object file
src/math/vclip/vclip.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o
.PHONY : src/math/vclip/vclip.cpp.o

src/math/vclip/vclip.i: src/math/vclip/vclip.cpp.i
.PHONY : src/math/vclip/vclip.i

# target to preprocess a source file
src/math/vclip/vclip.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vclip/vclip.cpp.i
.PHONY : src/math/vclip/vclip.cpp.i

src/math/vclip/vclip.s: src/math/vclip/vclip.cpp.s
.PHONY : src/math/vclip/vclip.s

# target to generate assembly for a file
src/math/vclip/vclip.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vclip/vclip.cpp.s
.PHONY : src/math/vclip/vclip.cpp.s

src/math/vec2.o: src/math/vec2.cpp.o
.PHONY : src/math/vec2.o

# target to build an object file
src/math/vec2.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec2.cpp.o
.PHONY : src/math/vec2.cpp.o

src/math/vec2.i: src/math/vec2.cpp.i
.PHONY : src/math/vec2.i

# target to preprocess a source file
src/math/vec2.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec2.cpp.i
.PHONY : src/math/vec2.cpp.i

src/math/vec2.s: src/math/vec2.cpp.s
.PHONY : src/math/vec2.s

# target to generate assembly for a file
src/math/vec2.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec2.cpp.s
.PHONY : src/math/vec2.cpp.s

src/math/vec3.o: src/math/vec3.cpp.o
.PHONY : src/math/vec3.o

# target to build an object file
src/math/vec3.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec3.cpp.o
.PHONY : src/math/vec3.cpp.o

src/math/vec3.i: src/math/vec3.cpp.i
.PHONY : src/math/vec3.i

# target to preprocess a source file
src/math/vec3.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec3.cpp.i
.PHONY : src/math/vec3.cpp.i

src/math/vec3.s: src/math/vec3.cpp.s
.PHONY : src/math/vec3.s

# target to generate assembly for a file
src/math/vec3.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec3.cpp.s
.PHONY : src/math/vec3.cpp.s

src/math/vec4.o: src/math/vec4.cpp.o
.PHONY : src/math/vec4.o

# target to build an object file
src/math/vec4.cpp.o:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec4.cpp.o
.PHONY : src/math/vec4.cpp.o

src/math/vec4.i: src/math/vec4.cpp.i
.PHONY : src/math/vec4.i

# target to preprocess a source file
src/math/vec4.cpp.i:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec4.cpp.i
.PHONY : src/math/vec4.cpp.i

src/math/vec4.s: src/math/vec4.cpp.s
.PHONY : src/math/vec4.s

# target to generate assembly for a file
src/math/vec4.cpp.s:
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec4.cpp.s
.PHONY : src/math/vec4.cpp.s

test/array/main.o: test/array/main.cpp.o
.PHONY : test/array/main.o

# target to build an object file
test/array/main.cpp.o:
	$(MAKE) -f CMakeFiles/test_array.dir/build.make CMakeFiles/test_array.dir/test/array/main.cpp.o
.PHONY : test/array/main.cpp.o

test/array/main.i: test/array/main.cpp.i
.PHONY : test/array/main.i

# target to preprocess a source file
test/array/main.cpp.i:
	$(MAKE) -f CMakeFiles/test_array.dir/build.make CMakeFiles/test_array.dir/test/array/main.cpp.i
.PHONY : test/array/main.cpp.i

test/array/main.s: test/array/main.cpp.s
.PHONY : test/array/main.s

# target to generate assembly for a file
test/array/main.cpp.s:
	$(MAKE) -f CMakeFiles/test_array.dir/build.make CMakeFiles/test_array.dir/test/array/main.cpp.s
.PHONY : test/array/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... doc"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... math"
	@echo "... rebuild_cache"
	@echo "... test_array"
	@echo "... src/math/color.o"
	@echo "... src/math/color.i"
	@echo "... src/math/color.s"
	@echo "... src/math/free.o"
	@echo "... src/math/free.i"
	@echo "... src/math/free.s"
	@echo "... src/math/geo/polyhedron.o"
	@echo "... src/math/geo/polyhedron.i"
	@echo "... src/math/geo/polyhedron.s"
	@echo "... src/math/mat33.o"
	@echo "... src/math/mat33.i"
	@echo "... src/math/mat33.s"
	@echo "... src/math/mat44.o"
	@echo "... src/math/mat44.i"
	@echo "... src/math/mat44.s"
	@echo "... src/math/plane.o"
	@echo "... src/math/plane.i"
	@echo "... src/math/plane.s"
	@echo "... src/math/quat.o"
	@echo "... src/math/quat.i"
	@echo "... src/math/quat.s"
	@echo "... src/math/transform.o"
	@echo "... src/math/transform.i"
	@echo "... src/math/transform.s"
	@echo "... src/math/vclip/vclip.o"
	@echo "... src/math/vclip/vclip.i"
	@echo "... src/math/vclip/vclip.s"
	@echo "... src/math/vec2.o"
	@echo "... src/math/vec2.i"
	@echo "... src/math/vec2.s"
	@echo "... src/math/vec3.o"
	@echo "... src/math/vec3.i"
	@echo "... src/math/vec3.s"
	@echo "... src/math/vec4.o"
	@echo "... src/math/vec4.i"
	@echo "... src/math/vec4.s"
	@echo "... test/array/main.o"
	@echo "... test/array/main.i"
	@echo "... test/array/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

