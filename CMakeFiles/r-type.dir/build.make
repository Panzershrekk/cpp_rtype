# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thomas/rendu3/cpp_rtype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/rendu3/cpp_rtype

# Include any dependencies generated for this target.
include CMakeFiles/r-type.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/r-type.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/r-type.dir/flags.make

CMakeFiles/r-type.dir/main.cpp.o: CMakeFiles/r-type.dir/flags.make
CMakeFiles/r-type.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/rendu3/cpp_rtype/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/r-type.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type.dir/main.cpp.o -c /home/thomas/rendu3/cpp_rtype/main.cpp

CMakeFiles/r-type.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/rendu3/cpp_rtype/main.cpp > CMakeFiles/r-type.dir/main.cpp.i

CMakeFiles/r-type.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/rendu3/cpp_rtype/main.cpp -o CMakeFiles/r-type.dir/main.cpp.s

CMakeFiles/r-type.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/r-type.dir/main.cpp.o.requires

CMakeFiles/r-type.dir/main.cpp.o.provides: CMakeFiles/r-type.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/r-type.dir/build.make CMakeFiles/r-type.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/r-type.dir/main.cpp.o.provides

CMakeFiles/r-type.dir/main.cpp.o.provides.build: CMakeFiles/r-type.dir/main.cpp.o


# Object files for target r-type
r__type_OBJECTS = \
"CMakeFiles/r-type.dir/main.cpp.o"

# External object files for target r-type
r__type_EXTERNAL_OBJECTS =

r-type: CMakeFiles/r-type.dir/main.cpp.o
r-type: CMakeFiles/r-type.dir/build.make
r-type: /usr/lib/libsfml-network.so
r-type: /usr/lib/libsfml-audio.so
r-type: /usr/lib/libsfml-graphics.so
r-type: /usr/lib/libsfml-window.so
r-type: /usr/lib/libsfml-system.so
r-type: CMakeFiles/r-type.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/rendu3/cpp_rtype/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable r-type"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r-type.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/r-type.dir/build: r-type

.PHONY : CMakeFiles/r-type.dir/build

CMakeFiles/r-type.dir/requires: CMakeFiles/r-type.dir/main.cpp.o.requires

.PHONY : CMakeFiles/r-type.dir/requires

CMakeFiles/r-type.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/r-type.dir/cmake_clean.cmake
.PHONY : CMakeFiles/r-type.dir/clean

CMakeFiles/r-type.dir/depend:
	cd /home/thomas/rendu3/cpp_rtype && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/rendu3/cpp_rtype /home/thomas/rendu3/cpp_rtype /home/thomas/rendu3/cpp_rtype /home/thomas/rendu3/cpp_rtype /home/thomas/rendu3/cpp_rtype/CMakeFiles/r-type.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/r-type.dir/depend

