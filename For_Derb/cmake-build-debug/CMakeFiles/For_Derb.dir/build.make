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
CMAKE_SOURCE_DIR = /home/sergey/CLionProjects/For_Derb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergey/CLionProjects/For_Derb/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/For_Derb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/For_Derb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/For_Derb.dir/flags.make

CMakeFiles/For_Derb.dir/main.cpp.o: CMakeFiles/For_Derb.dir/flags.make
CMakeFiles/For_Derb.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/For_Derb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/For_Derb.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/For_Derb.dir/main.cpp.o -c /home/sergey/CLionProjects/For_Derb/main.cpp

CMakeFiles/For_Derb.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/For_Derb.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/For_Derb/main.cpp > CMakeFiles/For_Derb.dir/main.cpp.i

CMakeFiles/For_Derb.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/For_Derb.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/For_Derb/main.cpp -o CMakeFiles/For_Derb.dir/main.cpp.s

CMakeFiles/For_Derb.dir/Erorr.cpp.o: CMakeFiles/For_Derb.dir/flags.make
CMakeFiles/For_Derb.dir/Erorr.cpp.o: ../Erorr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/For_Derb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/For_Derb.dir/Erorr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/For_Derb.dir/Erorr.cpp.o -c /home/sergey/CLionProjects/For_Derb/Erorr.cpp

CMakeFiles/For_Derb.dir/Erorr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/For_Derb.dir/Erorr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/For_Derb/Erorr.cpp > CMakeFiles/For_Derb.dir/Erorr.cpp.i

CMakeFiles/For_Derb.dir/Erorr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/For_Derb.dir/Erorr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/For_Derb/Erorr.cpp -o CMakeFiles/For_Derb.dir/Erorr.cpp.s

# Object files for target For_Derb
For_Derb_OBJECTS = \
"CMakeFiles/For_Derb.dir/main.cpp.o" \
"CMakeFiles/For_Derb.dir/Erorr.cpp.o"

# External object files for target For_Derb
For_Derb_EXTERNAL_OBJECTS =

For_Derb: CMakeFiles/For_Derb.dir/main.cpp.o
For_Derb: CMakeFiles/For_Derb.dir/Erorr.cpp.o
For_Derb: CMakeFiles/For_Derb.dir/build.make
For_Derb: CMakeFiles/For_Derb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergey/CLionProjects/For_Derb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable For_Derb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/For_Derb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/For_Derb.dir/build: For_Derb

.PHONY : CMakeFiles/For_Derb.dir/build

CMakeFiles/For_Derb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/For_Derb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/For_Derb.dir/clean

CMakeFiles/For_Derb.dir/depend:
	cd /home/sergey/CLionProjects/For_Derb/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergey/CLionProjects/For_Derb /home/sergey/CLionProjects/For_Derb /home/sergey/CLionProjects/For_Derb/cmake-build-debug /home/sergey/CLionProjects/For_Derb/cmake-build-debug /home/sergey/CLionProjects/For_Derb/cmake-build-debug/CMakeFiles/For_Derb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/For_Derb.dir/depend

