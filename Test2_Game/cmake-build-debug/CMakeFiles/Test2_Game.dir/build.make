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
CMAKE_SOURCE_DIR = /home/sergey/CLionProjects/Test2_Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergey/CLionProjects/Test2_Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Test2_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test2_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test2_Game.dir/flags.make

CMakeFiles/Test2_Game.dir/main.cpp.o: CMakeFiles/Test2_Game.dir/flags.make
CMakeFiles/Test2_Game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/Test2_Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test2_Game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test2_Game.dir/main.cpp.o -c /home/sergey/CLionProjects/Test2_Game/main.cpp

CMakeFiles/Test2_Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test2_Game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/Test2_Game/main.cpp > CMakeFiles/Test2_Game.dir/main.cpp.i

CMakeFiles/Test2_Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test2_Game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/Test2_Game/main.cpp -o CMakeFiles/Test2_Game.dir/main.cpp.s

# Object files for target Test2_Game
Test2_Game_OBJECTS = \
"CMakeFiles/Test2_Game.dir/main.cpp.o"

# External object files for target Test2_Game
Test2_Game_EXTERNAL_OBJECTS =

Test2_Game: CMakeFiles/Test2_Game.dir/main.cpp.o
Test2_Game: CMakeFiles/Test2_Game.dir/build.make
Test2_Game: CMakeFiles/Test2_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergey/CLionProjects/Test2_Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test2_Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test2_Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test2_Game.dir/build: Test2_Game

.PHONY : CMakeFiles/Test2_Game.dir/build

CMakeFiles/Test2_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test2_Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test2_Game.dir/clean

CMakeFiles/Test2_Game.dir/depend:
	cd /home/sergey/CLionProjects/Test2_Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergey/CLionProjects/Test2_Game /home/sergey/CLionProjects/Test2_Game /home/sergey/CLionProjects/Test2_Game/cmake-build-debug /home/sergey/CLionProjects/Test2_Game/cmake-build-debug /home/sergey/CLionProjects/Test2_Game/cmake-build-debug/CMakeFiles/Test2_Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test2_Game.dir/depend

