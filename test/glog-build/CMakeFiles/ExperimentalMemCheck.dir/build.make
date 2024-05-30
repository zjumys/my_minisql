# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Database/lab6/minisql

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Database/lab6/minisql/test

# Utility rule file for ExperimentalMemCheck.

# Include any custom commands dependencies for this target.
include glog-build/CMakeFiles/ExperimentalMemCheck.dir/compiler_depend.make

# Include the progress variables for this target.
include glog-build/CMakeFiles/ExperimentalMemCheck.dir/progress.make

glog-build/CMakeFiles/ExperimentalMemCheck:
	cd /root/Database/lab6/minisql/test/glog-build && /usr/local/cmake/bin/ctest -D ExperimentalMemCheck

ExperimentalMemCheck: glog-build/CMakeFiles/ExperimentalMemCheck
ExperimentalMemCheck: glog-build/CMakeFiles/ExperimentalMemCheck.dir/build.make
.PHONY : ExperimentalMemCheck

# Rule to build all files generated by this target.
glog-build/CMakeFiles/ExperimentalMemCheck.dir/build: ExperimentalMemCheck
.PHONY : glog-build/CMakeFiles/ExperimentalMemCheck.dir/build

glog-build/CMakeFiles/ExperimentalMemCheck.dir/clean:
	cd /root/Database/lab6/minisql/test/glog-build && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalMemCheck.dir/cmake_clean.cmake
.PHONY : glog-build/CMakeFiles/ExperimentalMemCheck.dir/clean

glog-build/CMakeFiles/ExperimentalMemCheck.dir/depend:
	cd /root/Database/lab6/minisql/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Database/lab6/minisql /root/Database/lab6/minisql/thirdparty/glog /root/Database/lab6/minisql/test /root/Database/lab6/minisql/test/glog-build /root/Database/lab6/minisql/test/glog-build/CMakeFiles/ExperimentalMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glog-build/CMakeFiles/ExperimentalMemCheck.dir/depend

