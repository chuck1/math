# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/stak/students/r/rymalc/Programming/C++/math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/stak/students/r/rymalc/Programming/C++/math

# Include any dependencies generated for this target.
include CMakeFiles/math.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/math.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/math.dir/flags.make

CMakeFiles/math.dir/src/math/free.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/free.cpp.o: src/math/free.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/free.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/free.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/free.cpp

CMakeFiles/math.dir/src/math/free.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/free.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/free.cpp > CMakeFiles/math.dir/src/math/free.cpp.i

CMakeFiles/math.dir/src/math/free.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/free.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/free.cpp -o CMakeFiles/math.dir/src/math/free.cpp.s

CMakeFiles/math.dir/src/math/free.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/free.cpp.o.requires

CMakeFiles/math.dir/src/math/free.cpp.o.provides: CMakeFiles/math.dir/src/math/free.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/free.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/free.cpp.o.provides

CMakeFiles/math.dir/src/math/free.cpp.o.provides.build: CMakeFiles/math.dir/src/math/free.cpp.o

CMakeFiles/math.dir/src/math/vec2.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/vec2.cpp.o: src/math/vec2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/vec2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/vec2.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec2.cpp

CMakeFiles/math.dir/src/math/vec2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/vec2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec2.cpp > CMakeFiles/math.dir/src/math/vec2.cpp.i

CMakeFiles/math.dir/src/math/vec2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/vec2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec2.cpp -o CMakeFiles/math.dir/src/math/vec2.cpp.s

CMakeFiles/math.dir/src/math/vec2.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/vec2.cpp.o.requires

CMakeFiles/math.dir/src/math/vec2.cpp.o.provides: CMakeFiles/math.dir/src/math/vec2.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec2.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/vec2.cpp.o.provides

CMakeFiles/math.dir/src/math/vec2.cpp.o.provides.build: CMakeFiles/math.dir/src/math/vec2.cpp.o

CMakeFiles/math.dir/src/math/vec3.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/vec3.cpp.o: src/math/vec3.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/vec3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/vec3.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec3.cpp

CMakeFiles/math.dir/src/math/vec3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/vec3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec3.cpp > CMakeFiles/math.dir/src/math/vec3.cpp.i

CMakeFiles/math.dir/src/math/vec3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/vec3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec3.cpp -o CMakeFiles/math.dir/src/math/vec3.cpp.s

CMakeFiles/math.dir/src/math/vec3.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/vec3.cpp.o.requires

CMakeFiles/math.dir/src/math/vec3.cpp.o.provides: CMakeFiles/math.dir/src/math/vec3.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec3.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/vec3.cpp.o.provides

CMakeFiles/math.dir/src/math/vec3.cpp.o.provides.build: CMakeFiles/math.dir/src/math/vec3.cpp.o

CMakeFiles/math.dir/src/math/vec4.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/vec4.cpp.o: src/math/vec4.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/vec4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/vec4.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec4.cpp

CMakeFiles/math.dir/src/math/vec4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/vec4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec4.cpp > CMakeFiles/math.dir/src/math/vec4.cpp.i

CMakeFiles/math.dir/src/math/vec4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/vec4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vec4.cpp -o CMakeFiles/math.dir/src/math/vec4.cpp.s

CMakeFiles/math.dir/src/math/vec4.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/vec4.cpp.o.requires

CMakeFiles/math.dir/src/math/vec4.cpp.o.provides: CMakeFiles/math.dir/src/math/vec4.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vec4.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/vec4.cpp.o.provides

CMakeFiles/math.dir/src/math/vec4.cpp.o.provides.build: CMakeFiles/math.dir/src/math/vec4.cpp.o

CMakeFiles/math.dir/src/math/mat33.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/mat33.cpp.o: src/math/mat33.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/mat33.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/mat33.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/mat33.cpp

CMakeFiles/math.dir/src/math/mat33.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/mat33.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/mat33.cpp > CMakeFiles/math.dir/src/math/mat33.cpp.i

CMakeFiles/math.dir/src/math/mat33.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/mat33.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/mat33.cpp -o CMakeFiles/math.dir/src/math/mat33.cpp.s

CMakeFiles/math.dir/src/math/mat33.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/mat33.cpp.o.requires

CMakeFiles/math.dir/src/math/mat33.cpp.o.provides: CMakeFiles/math.dir/src/math/mat33.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat33.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/mat33.cpp.o.provides

CMakeFiles/math.dir/src/math/mat33.cpp.o.provides.build: CMakeFiles/math.dir/src/math/mat33.cpp.o

CMakeFiles/math.dir/src/math/mat44.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/mat44.cpp.o: src/math/mat44.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/mat44.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/mat44.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/mat44.cpp

CMakeFiles/math.dir/src/math/mat44.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/mat44.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/mat44.cpp > CMakeFiles/math.dir/src/math/mat44.cpp.i

CMakeFiles/math.dir/src/math/mat44.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/mat44.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/mat44.cpp -o CMakeFiles/math.dir/src/math/mat44.cpp.s

CMakeFiles/math.dir/src/math/mat44.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/mat44.cpp.o.requires

CMakeFiles/math.dir/src/math/mat44.cpp.o.provides: CMakeFiles/math.dir/src/math/mat44.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/mat44.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/mat44.cpp.o.provides

CMakeFiles/math.dir/src/math/mat44.cpp.o.provides.build: CMakeFiles/math.dir/src/math/mat44.cpp.o

CMakeFiles/math.dir/src/math/plane.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/plane.cpp.o: src/math/plane.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/plane.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/plane.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/plane.cpp

CMakeFiles/math.dir/src/math/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/plane.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/plane.cpp > CMakeFiles/math.dir/src/math/plane.cpp.i

CMakeFiles/math.dir/src/math/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/plane.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/plane.cpp -o CMakeFiles/math.dir/src/math/plane.cpp.s

CMakeFiles/math.dir/src/math/plane.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/plane.cpp.o.requires

CMakeFiles/math.dir/src/math/plane.cpp.o.provides: CMakeFiles/math.dir/src/math/plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/plane.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/plane.cpp.o.provides

CMakeFiles/math.dir/src/math/plane.cpp.o.provides.build: CMakeFiles/math.dir/src/math/plane.cpp.o

CMakeFiles/math.dir/src/math/color.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/color.cpp.o: src/math/color.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/color.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/color.cpp

CMakeFiles/math.dir/src/math/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/color.cpp > CMakeFiles/math.dir/src/math/color.cpp.i

CMakeFiles/math.dir/src/math/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/color.cpp -o CMakeFiles/math.dir/src/math/color.cpp.s

CMakeFiles/math.dir/src/math/color.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/color.cpp.o.requires

CMakeFiles/math.dir/src/math/color.cpp.o.provides: CMakeFiles/math.dir/src/math/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/color.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/color.cpp.o.provides

CMakeFiles/math.dir/src/math/color.cpp.o.provides.build: CMakeFiles/math.dir/src/math/color.cpp.o

CMakeFiles/math.dir/src/math/quat.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/quat.cpp.o: src/math/quat.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/quat.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/quat.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/quat.cpp

CMakeFiles/math.dir/src/math/quat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/quat.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/quat.cpp > CMakeFiles/math.dir/src/math/quat.cpp.i

CMakeFiles/math.dir/src/math/quat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/quat.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/quat.cpp -o CMakeFiles/math.dir/src/math/quat.cpp.s

CMakeFiles/math.dir/src/math/quat.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/quat.cpp.o.requires

CMakeFiles/math.dir/src/math/quat.cpp.o.provides: CMakeFiles/math.dir/src/math/quat.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/quat.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/quat.cpp.o.provides

CMakeFiles/math.dir/src/math/quat.cpp.o.provides.build: CMakeFiles/math.dir/src/math/quat.cpp.o

CMakeFiles/math.dir/src/math/transform.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/transform.cpp.o: src/math/transform.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/transform.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/transform.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/transform.cpp

CMakeFiles/math.dir/src/math/transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/transform.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/transform.cpp > CMakeFiles/math.dir/src/math/transform.cpp.i

CMakeFiles/math.dir/src/math/transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/transform.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/transform.cpp -o CMakeFiles/math.dir/src/math/transform.cpp.s

CMakeFiles/math.dir/src/math/transform.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/transform.cpp.o.requires

CMakeFiles/math.dir/src/math/transform.cpp.o.provides: CMakeFiles/math.dir/src/math/transform.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/transform.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/transform.cpp.o.provides

CMakeFiles/math.dir/src/math/transform.cpp.o.provides.build: CMakeFiles/math.dir/src/math/transform.cpp.o

CMakeFiles/math.dir/src/math/raw/raw.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/raw/raw.cpp.o: src/math/raw/raw.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/raw/raw.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/raw/raw.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/raw/raw.cpp

CMakeFiles/math.dir/src/math/raw/raw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/raw/raw.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/raw/raw.cpp > CMakeFiles/math.dir/src/math/raw/raw.cpp.i

CMakeFiles/math.dir/src/math/raw/raw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/raw/raw.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/raw/raw.cpp -o CMakeFiles/math.dir/src/math/raw/raw.cpp.s

CMakeFiles/math.dir/src/math/raw/raw.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/raw/raw.cpp.o.requires

CMakeFiles/math.dir/src/math/raw/raw.cpp.o.provides: CMakeFiles/math.dir/src/math/raw/raw.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/raw/raw.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/raw/raw.cpp.o.provides

CMakeFiles/math.dir/src/math/raw/raw.cpp.o.provides.build: CMakeFiles/math.dir/src/math/raw/raw.cpp.o

CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o: src/math/geo/polyhedron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/geo/polyhedron.cpp

CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/geo/polyhedron.cpp > CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.i

CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/geo/polyhedron.cpp -o CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.s

CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.requires

CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.provides: CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.provides

CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.provides.build: CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o

CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o: src/math/vclip/vclip.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o -c /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vclip/vclip.cpp

CMakeFiles/math.dir/src/math/vclip/vclip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/src/math/vclip/vclip.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vclip/vclip.cpp > CMakeFiles/math.dir/src/math/vclip/vclip.cpp.i

CMakeFiles/math.dir/src/math/vclip/vclip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/src/math/vclip/vclip.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nfs/stak/students/r/rymalc/Programming/C++/math/src/math/vclip/vclip.cpp -o CMakeFiles/math.dir/src/math/vclip/vclip.cpp.s

CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.requires:
.PHONY : CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.requires

CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.provides: CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.requires
	$(MAKE) -f CMakeFiles/math.dir/build.make CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.provides.build
.PHONY : CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.provides

CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.provides.build: CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o

# Object files for target math
math_OBJECTS = \
"CMakeFiles/math.dir/src/math/free.cpp.o" \
"CMakeFiles/math.dir/src/math/vec2.cpp.o" \
"CMakeFiles/math.dir/src/math/vec3.cpp.o" \
"CMakeFiles/math.dir/src/math/vec4.cpp.o" \
"CMakeFiles/math.dir/src/math/mat33.cpp.o" \
"CMakeFiles/math.dir/src/math/mat44.cpp.o" \
"CMakeFiles/math.dir/src/math/plane.cpp.o" \
"CMakeFiles/math.dir/src/math/color.cpp.o" \
"CMakeFiles/math.dir/src/math/quat.cpp.o" \
"CMakeFiles/math.dir/src/math/transform.cpp.o" \
"CMakeFiles/math.dir/src/math/raw/raw.cpp.o" \
"CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o" \
"CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o"

# External object files for target math
math_EXTERNAL_OBJECTS =

libmath.a: CMakeFiles/math.dir/src/math/free.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/vec2.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/vec3.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/vec4.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/mat33.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/mat44.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/plane.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/color.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/quat.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/transform.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/raw/raw.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o
libmath.a: CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o
libmath.a: CMakeFiles/math.dir/build.make
libmath.a: CMakeFiles/math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libmath.a"
	$(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/math.dir/build: libmath.a
.PHONY : CMakeFiles/math.dir/build

CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/free.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/vec2.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/vec3.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/vec4.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/mat33.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/mat44.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/plane.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/color.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/quat.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/transform.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/raw/raw.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/geo/polyhedron.cpp.o.requires
CMakeFiles/math.dir/requires: CMakeFiles/math.dir/src/math/vclip/vclip.cpp.o.requires
.PHONY : CMakeFiles/math.dir/requires

CMakeFiles/math.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean.cmake
.PHONY : CMakeFiles/math.dir/clean

CMakeFiles/math.dir/depend:
	cd /nfs/stak/students/r/rymalc/Programming/C++/math && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/stak/students/r/rymalc/Programming/C++/math /nfs/stak/students/r/rymalc/Programming/C++/math /nfs/stak/students/r/rymalc/Programming/C++/math /nfs/stak/students/r/rymalc/Programming/C++/math /nfs/stak/students/r/rymalc/Programming/C++/math/CMakeFiles/math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/math.dir/depend

