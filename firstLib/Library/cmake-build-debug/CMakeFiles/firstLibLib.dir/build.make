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
CMAKE_COMMAND = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/firstLibLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/firstLibLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firstLibLib.dir/flags.make

CMakeFiles/firstLibLib.dir/src/lib.cpp.o: CMakeFiles/firstLibLib.dir/flags.make
CMakeFiles/firstLibLib.dir/src/lib.cpp.o: ../src/lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/firstLibLib.dir/src/lib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstLibLib.dir/src/lib.cpp.o -c /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/src/lib.cpp

CMakeFiles/firstLibLib.dir/src/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstLibLib.dir/src/lib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/src/lib.cpp > CMakeFiles/firstLibLib.dir/src/lib.cpp.i

CMakeFiles/firstLibLib.dir/src/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstLibLib.dir/src/lib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/src/lib.cpp -o CMakeFiles/firstLibLib.dir/src/lib.cpp.s

# Object files for target firstLibLib
firstLibLib_OBJECTS = \
"CMakeFiles/firstLibLib.dir/src/lib.cpp.o"

# External object files for target firstLibLib
firstLibLib_EXTERNAL_OBJECTS =

libfirstLibLib.a: CMakeFiles/firstLibLib.dir/src/lib.cpp.o
libfirstLibLib.a: CMakeFiles/firstLibLib.dir/build.make
libfirstLibLib.a: CMakeFiles/firstLibLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfirstLibLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/firstLibLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/firstLibLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firstLibLib.dir/build: libfirstLibLib.a

.PHONY : CMakeFiles/firstLibLib.dir/build

CMakeFiles/firstLibLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firstLibLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firstLibLib.dir/clean

CMakeFiles/firstLibLib.dir/depend:
	cd /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug /home/student/Pulpit/nowyxd/JiPP2/firstLib/Library/cmake-build-debug/CMakeFiles/firstLibLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firstLibLib.dir/depend
