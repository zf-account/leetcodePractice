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
include CMakeFiles/415ZiFuChuanXiangJia.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/415ZiFuChuanXiangJia.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/415ZiFuChuanXiangJia.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/415ZiFuChuanXiangJia.dir/flags.make

CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o: CMakeFiles/415ZiFuChuanXiangJia.dir/flags.make
CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o: ../src/415ZiFuChuanXiangJia.cpp
CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o: CMakeFiles/415ZiFuChuanXiangJia.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o -MF CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o.d -o CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o -c /home/kemove/vscode_workspace/LeetcodePracticeC++/src/415ZiFuChuanXiangJia.cpp

CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kemove/vscode_workspace/LeetcodePracticeC++/src/415ZiFuChuanXiangJia.cpp > CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.i

CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kemove/vscode_workspace/LeetcodePracticeC++/src/415ZiFuChuanXiangJia.cpp -o CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.s

# Object files for target 415ZiFuChuanXiangJia
415ZiFuChuanXiangJia_OBJECTS = \
"CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o"

# External object files for target 415ZiFuChuanXiangJia
415ZiFuChuanXiangJia_EXTERNAL_OBJECTS =

415ZiFuChuanXiangJia: CMakeFiles/415ZiFuChuanXiangJia.dir/src/415ZiFuChuanXiangJia.cpp.o
415ZiFuChuanXiangJia: CMakeFiles/415ZiFuChuanXiangJia.dir/build.make
415ZiFuChuanXiangJia: CMakeFiles/415ZiFuChuanXiangJia.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 415ZiFuChuanXiangJia"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/415ZiFuChuanXiangJia.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/415ZiFuChuanXiangJia.dir/build: 415ZiFuChuanXiangJia
.PHONY : CMakeFiles/415ZiFuChuanXiangJia.dir/build

CMakeFiles/415ZiFuChuanXiangJia.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/415ZiFuChuanXiangJia.dir/cmake_clean.cmake
.PHONY : CMakeFiles/415ZiFuChuanXiangJia.dir/clean

CMakeFiles/415ZiFuChuanXiangJia.dir/depend:
	cd /home/kemove/vscode_workspace/LeetcodePracticeC++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles/415ZiFuChuanXiangJia.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/415ZiFuChuanXiangJia.dir/depend

