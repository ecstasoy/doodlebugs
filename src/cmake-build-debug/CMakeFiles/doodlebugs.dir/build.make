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
CMAKE_SOURCE_DIR = /Users/kw/personal_projects/doodlebugs/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kw/personal_projects/doodlebugs/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/doodlebugs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/doodlebugs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/doodlebugs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doodlebugs.dir/flags.make

CMakeFiles/doodlebugs.dir/Game.cpp.o: CMakeFiles/doodlebugs.dir/flags.make
CMakeFiles/doodlebugs.dir/Game.cpp.o: /Users/kw/personal_projects/doodlebugs/src/Game.cpp
CMakeFiles/doodlebugs.dir/Game.cpp.o: CMakeFiles/doodlebugs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kw/personal_projects/doodlebugs/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/doodlebugs.dir/Game.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doodlebugs.dir/Game.cpp.o -MF CMakeFiles/doodlebugs.dir/Game.cpp.o.d -o CMakeFiles/doodlebugs.dir/Game.cpp.o -c /Users/kw/personal_projects/doodlebugs/src/Game.cpp

CMakeFiles/doodlebugs.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doodlebugs.dir/Game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kw/personal_projects/doodlebugs/src/Game.cpp > CMakeFiles/doodlebugs.dir/Game.cpp.i

CMakeFiles/doodlebugs.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doodlebugs.dir/Game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kw/personal_projects/doodlebugs/src/Game.cpp -o CMakeFiles/doodlebugs.dir/Game.cpp.s

CMakeFiles/doodlebugs.dir/Organism.cpp.o: CMakeFiles/doodlebugs.dir/flags.make
CMakeFiles/doodlebugs.dir/Organism.cpp.o: /Users/kw/personal_projects/doodlebugs/src/Organism.cpp
CMakeFiles/doodlebugs.dir/Organism.cpp.o: CMakeFiles/doodlebugs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kw/personal_projects/doodlebugs/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/doodlebugs.dir/Organism.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doodlebugs.dir/Organism.cpp.o -MF CMakeFiles/doodlebugs.dir/Organism.cpp.o.d -o CMakeFiles/doodlebugs.dir/Organism.cpp.o -c /Users/kw/personal_projects/doodlebugs/src/Organism.cpp

CMakeFiles/doodlebugs.dir/Organism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doodlebugs.dir/Organism.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kw/personal_projects/doodlebugs/src/Organism.cpp > CMakeFiles/doodlebugs.dir/Organism.cpp.i

CMakeFiles/doodlebugs.dir/Organism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doodlebugs.dir/Organism.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kw/personal_projects/doodlebugs/src/Organism.cpp -o CMakeFiles/doodlebugs.dir/Organism.cpp.s

CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o: CMakeFiles/doodlebugs.dir/flags.make
CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o: /Users/kw/personal_projects/doodlebugs/src/doodlebugs.cpp
CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o: CMakeFiles/doodlebugs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kw/personal_projects/doodlebugs/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o -MF CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o.d -o CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o -c /Users/kw/personal_projects/doodlebugs/src/doodlebugs.cpp

CMakeFiles/doodlebugs.dir/doodlebugs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doodlebugs.dir/doodlebugs.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kw/personal_projects/doodlebugs/src/doodlebugs.cpp > CMakeFiles/doodlebugs.dir/doodlebugs.cpp.i

CMakeFiles/doodlebugs.dir/doodlebugs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doodlebugs.dir/doodlebugs.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kw/personal_projects/doodlebugs/src/doodlebugs.cpp -o CMakeFiles/doodlebugs.dir/doodlebugs.cpp.s

# Object files for target doodlebugs
doodlebugs_OBJECTS = \
"CMakeFiles/doodlebugs.dir/Game.cpp.o" \
"CMakeFiles/doodlebugs.dir/Organism.cpp.o" \
"CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o"

# External object files for target doodlebugs
doodlebugs_EXTERNAL_OBJECTS =

doodlebugs: CMakeFiles/doodlebugs.dir/Game.cpp.o
doodlebugs: CMakeFiles/doodlebugs.dir/Organism.cpp.o
doodlebugs: CMakeFiles/doodlebugs.dir/doodlebugs.cpp.o
doodlebugs: CMakeFiles/doodlebugs.dir/build.make
doodlebugs: CMakeFiles/doodlebugs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/kw/personal_projects/doodlebugs/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable doodlebugs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/doodlebugs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doodlebugs.dir/build: doodlebugs
.PHONY : CMakeFiles/doodlebugs.dir/build

CMakeFiles/doodlebugs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doodlebugs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doodlebugs.dir/clean

CMakeFiles/doodlebugs.dir/depend:
	cd /Users/kw/personal_projects/doodlebugs/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kw/personal_projects/doodlebugs/src /Users/kw/personal_projects/doodlebugs/src /Users/kw/personal_projects/doodlebugs/src/cmake-build-debug /Users/kw/personal_projects/doodlebugs/src/cmake-build-debug /Users/kw/personal_projects/doodlebugs/src/cmake-build-debug/CMakeFiles/doodlebugs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/doodlebugs.dir/depend

