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
include CMakeFiles/LCR024FanZhuanLianBiao.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LCR024FanZhuanLianBiao.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LCR024FanZhuanLianBiao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LCR024FanZhuanLianBiao.dir/flags.make

CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o: CMakeFiles/LCR024FanZhuanLianBiao.dir/flags.make
CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o: ../src/LCR024FanZhuanLianBiao.cpp
CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o: CMakeFiles/LCR024FanZhuanLianBiao.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o -MF CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o.d -o CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o -c /home/kemove/vscode_workspace/LeetcodePracticeC++/src/LCR024FanZhuanLianBiao.cpp

CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kemove/vscode_workspace/LeetcodePracticeC++/src/LCR024FanZhuanLianBiao.cpp > CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.i

CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kemove/vscode_workspace/LeetcodePracticeC++/src/LCR024FanZhuanLianBiao.cpp -o CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.s

# Object files for target LCR024FanZhuanLianBiao
LCR024FanZhuanLianBiao_OBJECTS = \
"CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o"

# External object files for target LCR024FanZhuanLianBiao
LCR024FanZhuanLianBiao_EXTERNAL_OBJECTS =

LCR024FanZhuanLianBiao: CMakeFiles/LCR024FanZhuanLianBiao.dir/src/LCR024FanZhuanLianBiao.cpp.o
LCR024FanZhuanLianBiao: CMakeFiles/LCR024FanZhuanLianBiao.dir/build.make
LCR024FanZhuanLianBiao: CMakeFiles/LCR024FanZhuanLianBiao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LCR024FanZhuanLianBiao"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LCR024FanZhuanLianBiao.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LCR024FanZhuanLianBiao.dir/build: LCR024FanZhuanLianBiao
.PHONY : CMakeFiles/LCR024FanZhuanLianBiao.dir/build

CMakeFiles/LCR024FanZhuanLianBiao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LCR024FanZhuanLianBiao.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LCR024FanZhuanLianBiao.dir/clean

CMakeFiles/LCR024FanZhuanLianBiao.dir/depend:
	cd /home/kemove/vscode_workspace/LeetcodePracticeC++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++ /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build /home/kemove/vscode_workspace/LeetcodePracticeC++/build/CMakeFiles/LCR024FanZhuanLianBiao.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LCR024FanZhuanLianBiao.dir/depend

