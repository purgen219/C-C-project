# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sergey/CLionProjects/MySteck

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergey/CLionProjects/MySteck/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MySteck.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MySteck.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MySteck.dir/flags.make

CMakeFiles/MySteck.dir/main.cpp.o: CMakeFiles/MySteck.dir/flags.make
CMakeFiles/MySteck.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/MySteck/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MySteck.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySteck.dir/main.cpp.o -c /home/sergey/CLionProjects/MySteck/main.cpp

CMakeFiles/MySteck.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySteck.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/MySteck/main.cpp > CMakeFiles/MySteck.dir/main.cpp.i

CMakeFiles/MySteck.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySteck.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/MySteck/main.cpp -o CMakeFiles/MySteck.dir/main.cpp.s

# Object files for target MySteck
MySteck_OBJECTS = \
"CMakeFiles/MySteck.dir/main.cpp.o"

# External object files for target MySteck
MySteck_EXTERNAL_OBJECTS =

MySteck: CMakeFiles/MySteck.dir/main.cpp.o
MySteck: CMakeFiles/MySteck.dir/build.make
MySteck: CMakeFiles/MySteck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergey/CLionProjects/MySteck/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MySteck"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MySteck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MySteck.dir/build: MySteck

.PHONY : CMakeFiles/MySteck.dir/build

CMakeFiles/MySteck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MySteck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MySteck.dir/clean

CMakeFiles/MySteck.dir/depend:
	cd /home/sergey/CLionProjects/MySteck/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergey/CLionProjects/MySteck /home/sergey/CLionProjects/MySteck /home/sergey/CLionProjects/MySteck/cmake-build-debug /home/sergey/CLionProjects/MySteck/cmake-build-debug /home/sergey/CLionProjects/MySteck/cmake-build-debug/CMakeFiles/MySteck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MySteck.dir/depend

