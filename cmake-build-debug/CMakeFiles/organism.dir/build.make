# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kw/personal_projects/doodlebugs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kw/personal_projects/doodlebugs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/organism.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/organism.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/organism.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/organism.dir/flags.make

CMakeFiles/organism.dir/organism.cpp.o: CMakeFiles/organism.dir/flags.make
CMakeFiles/organism.dir/organism.cpp.o: /Users/kw/personal_projects/doodlebugs/organism.cpp
CMakeFiles/organism.dir/organism.cpp.o: CMakeFiles/organism.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kw/personal_projects/doodlebugs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/organism.dir/organism.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/organism.dir/organism.cpp.o -MF CMakeFiles/organism.dir/organism.cpp.o.d -o CMakeFiles/organism.dir/organism.cpp.o -c /Users/kw/personal_projects/doodlebugs/organism.cpp

CMakeFiles/organism.dir/organism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/organism.dir/organism.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kw/personal_projects/doodlebugs/organism.cpp > CMakeFiles/organism.dir/organism.cpp.i

CMakeFiles/organism.dir/organism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/organism.dir/organism.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kw/personal_projects/doodlebugs/organism.cpp -o CMakeFiles/organism.dir/organism.cpp.s

CMakeFiles/organism.dir/main.cpp.o: CMakeFiles/organism.dir/flags.make
CMakeFiles/organism.dir/main.cpp.o: /Users/kw/personal_projects/doodlebugs/main.cpp
CMakeFiles/organism.dir/main.cpp.o: CMakeFiles/organism.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kw/personal_projects/doodlebugs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/organism.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/organism.dir/main.cpp.o -MF CMakeFiles/organism.dir/main.cpp.o.d -o CMakeFiles/organism.dir/main.cpp.o -c /Users/kw/personal_projects/doodlebugs/main.cpp

CMakeFiles/organism.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/organism.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kw/personal_projects/doodlebugs/main.cpp > CMakeFiles/organism.dir/main.cpp.i

CMakeFiles/organism.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/organism.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kw/personal_projects/doodlebugs/main.cpp -o CMakeFiles/organism.dir/main.cpp.s

# Object files for target organism
organism_OBJECTS = \
"CMakeFiles/organism.dir/organism.cpp.o" \
"CMakeFiles/organism.dir/main.cpp.o"

# External object files for target organism
organism_EXTERNAL_OBJECTS =

organism: CMakeFiles/organism.dir/organism.cpp.o
organism: CMakeFiles/organism.dir/main.cpp.o
organism: CMakeFiles/organism.dir/build.make
organism: CMakeFiles/organism.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/kw/personal_projects/doodlebugs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable organism"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/organism.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/organism.dir/build: organism
.PHONY : CMakeFiles/organism.dir/build

CMakeFiles/organism.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/organism.dir/cmake_clean.cmake
.PHONY : CMakeFiles/organism.dir/clean

CMakeFiles/organism.dir/depend:
	cd /Users/kw/personal_projects/doodlebugs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kw/personal_projects/doodlebugs /Users/kw/personal_projects/doodlebugs /Users/kw/personal_projects/doodlebugs/cmake-build-debug /Users/kw/personal_projects/doodlebugs/cmake-build-debug /Users/kw/personal_projects/doodlebugs/cmake-build-debug/CMakeFiles/organism.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/organism.dir/depend

