# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kemove/vscode_workspace/LeetcodePracticeC++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kemove/vscode_workspace/LeetcodePracticeC++/build

# Include any dependencies generated for this target.
include CMakeFiles/66JiaYi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/66JiaYi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/66JiaYi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/66JiaYi.dir/flags.make

CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o: CMakeFiles/66JiaYi.dir/flags.make
CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o: ../src/66JiaYi.cpp
CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o: CMakeFiles/66JiaYi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o -MF CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o.d -o CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o -c /home/kemove/vscode_workspace/LeetcodePracticeC++/src/66JiaYi.cpp

CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kemove/vscode_workspace/LeetcodePracticeC++/src/66JiaYi.cpp > CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.i

CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kemove/vscode_workspace/LeetcodePracticeC++/src/66JiaYi.cpp -o CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.s

# Object files for target 66JiaYi
66JiaYi_OBJECTS = \
"CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o"

# External object files for target 66JiaYi
66JiaYi_EXTERNAL_OBJECTS =

66JiaYi: CMakeFiles/66JiaYi.dir/src/66JiaYi.cpp.o
66JiaYi: CMakeFiles/66JiaYi.dir/build.make
66JiaYi: CMakeFiles/66JiaYi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 66JiaYi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/66JiaYi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/66JiaYi.dir/build: 66JiaYi
.PHONY : CMakeFiles/66JiaYi.dir/build

CMakeFiles/66JiaYi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/66JiaYi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/66JiaYi.dir/clean

CMakeFiles/66JiaYi.dir/depend:
	cd /home/kemove/vscode_workspace/LeetcodePracticeC++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles/66JiaYi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/66JiaYi.dir/depend

