# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /opt/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nikokozak/learn/cpp/algos/radixsort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/radixsort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/radixsort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/radixsort.dir/flags.make

CMakeFiles/radixsort.dir/main.cpp.o: CMakeFiles/radixsort.dir/flags.make
CMakeFiles/radixsort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/radixsort.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/radixsort.dir/main.cpp.o -c /home/nikokozak/learn/cpp/algos/radixsort/main.cpp

CMakeFiles/radixsort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radixsort.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikokozak/learn/cpp/algos/radixsort/main.cpp > CMakeFiles/radixsort.dir/main.cpp.i

CMakeFiles/radixsort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radixsort.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikokozak/learn/cpp/algos/radixsort/main.cpp -o CMakeFiles/radixsort.dir/main.cpp.s

# Object files for target radixsort
radixsort_OBJECTS = \
"CMakeFiles/radixsort.dir/main.cpp.o"

# External object files for target radixsort
radixsort_EXTERNAL_OBJECTS =

radixsort: CMakeFiles/radixsort.dir/main.cpp.o
radixsort: CMakeFiles/radixsort.dir/build.make
radixsort: CMakeFiles/radixsort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable radixsort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/radixsort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/radixsort.dir/build: radixsort

.PHONY : CMakeFiles/radixsort.dir/build

CMakeFiles/radixsort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/radixsort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/radixsort.dir/clean

CMakeFiles/radixsort.dir/depend:
	cd /home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikokozak/learn/cpp/algos/radixsort /home/nikokozak/learn/cpp/algos/radixsort /home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug /home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug /home/nikokozak/learn/cpp/algos/radixsort/cmake-build-debug/CMakeFiles/radixsort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/radixsort.dir/depend

