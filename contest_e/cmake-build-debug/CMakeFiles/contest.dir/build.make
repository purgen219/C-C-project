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
CMAKE_SOURCE_DIR = /home/sergey/CLionProjects/contest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergey/CLionProjects/contest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/contest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/contest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/contest.dir/flags.make

CMakeFiles/contest.dir/main.c.o: CMakeFiles/contest.dir/flags.make
CMakeFiles/contest.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/contest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/contest.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/contest.dir/main.c.o   -c /home/sergey/CLionProjects/contest/main.c

CMakeFiles/contest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/contest.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sergey/CLionProjects/contest/main.c > CMakeFiles/contest.dir/main.c.i

CMakeFiles/contest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/contest.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sergey/CLionProjects/contest/main.c -o CMakeFiles/contest.dir/main.c.s

# Object files for target contest
contest_OBJECTS = \
"CMakeFiles/contest.dir/main.c.o"

# External object files for target contest
contest_EXTERNAL_OBJECTS =

contest: CMakeFiles/contest.dir/main.c.o
contest: CMakeFiles/contest.dir/build.make
contest: CMakeFiles/contest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergey/CLionProjects/contest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable contest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/contest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/contest.dir/build: contest

.PHONY : CMakeFiles/contest.dir/build

CMakeFiles/contest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/contest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/contest.dir/clean

CMakeFiles/contest.dir/depend:
	cd /home/sergey/CLionProjects/contest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergey/CLionProjects/contest /home/sergey/CLionProjects/contest /home/sergey/CLionProjects/contest/cmake-build-debug /home/sergey/CLionProjects/contest/cmake-build-debug /home/sergey/CLionProjects/contest/cmake-build-debug/CMakeFiles/contest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/contest.dir/depend

