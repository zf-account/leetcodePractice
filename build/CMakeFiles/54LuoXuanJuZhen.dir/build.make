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
include CMakeFiles/54LuoXuanJuZhen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/54LuoXuanJuZhen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/54LuoXuanJuZhen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/54LuoXuanJuZhen.dir/flags.make

CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o: CMakeFiles/54LuoXuanJuZhen.dir/flags.make
CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o: ../src/54LuoXuanJuZhen.cpp
CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o: CMakeFiles/54LuoXuanJuZhen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o -MF CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o.d -o CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o -c /home/kemove/vscode_workspace/LeetcodePracticeC++/src/54LuoXuanJuZhen.cpp

CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kemove/vscode_workspace/LeetcodePracticeC++/src/54LuoXuanJuZhen.cpp > CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.i

CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kemove/vscode_workspace/LeetcodePracticeC++/src/54LuoXuanJuZhen.cpp -o CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.s

# Object files for target 54LuoXuanJuZhen
54LuoXuanJuZhen_OBJECTS = \
"CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o"

# External object files for target 54LuoXuanJuZhen
54LuoXuanJuZhen_EXTERNAL_OBJECTS =

54LuoXuanJuZhen: CMakeFiles/54LuoXuanJuZhen.dir/src/54LuoXuanJuZhen.cpp.o
54LuoXuanJuZhen: CMakeFiles/54LuoXuanJuZhen.dir/build.make
54LuoXuanJuZhen: CMakeFiles/54LuoXuanJuZhen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 54LuoXuanJuZhen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/54LuoXuanJuZhen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/54LuoXuanJuZhen.dir/build: 54LuoXuanJuZhen
.PHONY : CMakeFiles/54LuoXuanJuZhen.dir/build

CMakeFiles/54LuoXuanJuZhen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/54LuoXuanJuZhen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/54LuoXuanJuZhen.dir/clean

CMakeFiles/54LuoXuanJuZhen.dir/depend:
	cd /home/kemove/vscode_workspace/LeetcodePracticeC++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles/54LuoXuanJuZhen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/54LuoXuanJuZhen.dir/depend

