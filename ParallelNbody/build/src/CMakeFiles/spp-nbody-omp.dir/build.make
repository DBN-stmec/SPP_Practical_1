# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/kurse/kurs00062/je59nuni/ParallelNbody

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kurse/kurs00062/je59nuni/ParallelNbody/build

# Include any dependencies generated for this target.
include src/CMakeFiles/spp-nbody-omp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/spp-nbody-omp.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/spp-nbody-omp.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/spp-nbody-omp.dir/flags.make

src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/flags.make
src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o: ../src/OmpPractical.cpp
src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurse/kurs00062/je59nuni/ParallelNbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o -MF CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o.d -o CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o -c /home/kurse/kurs00062/je59nuni/ParallelNbody/src/OmpPractical.cpp

src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.i"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurse/kurs00062/je59nuni/ParallelNbody/src/OmpPractical.cpp > CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.i

src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.s"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurse/kurs00062/je59nuni/ParallelNbody/src/OmpPractical.cpp -o CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.s

src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/flags.make
src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.o: ../src/Body.cpp
src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurse/kurs00062/je59nuni/ParallelNbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.o"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.o -MF CMakeFiles/spp-nbody-omp.dir/Body.cpp.o.d -o CMakeFiles/spp-nbody-omp.dir/Body.cpp.o -c /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Body.cpp

src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spp-nbody-omp.dir/Body.cpp.i"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Body.cpp > CMakeFiles/spp-nbody-omp.dir/Body.cpp.i

src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spp-nbody-omp.dir/Body.cpp.s"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Body.cpp -o CMakeFiles/spp-nbody-omp.dir/Body.cpp.s

src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/flags.make
src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o: ../src/Simulation.cpp
src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurse/kurs00062/je59nuni/ParallelNbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o -MF CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o.d -o CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o -c /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Simulation.cpp

src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.i"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Simulation.cpp > CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.i

src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.s"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Simulation.cpp -o CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.s

src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/flags.make
src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.o: ../src/Config.cpp
src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.o: src/CMakeFiles/spp-nbody-omp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurse/kurs00062/je59nuni/ParallelNbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.o"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.o -MF CMakeFiles/spp-nbody-omp.dir/Config.cpp.o.d -o CMakeFiles/spp-nbody-omp.dir/Config.cpp.o -c /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Config.cpp

src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spp-nbody-omp.dir/Config.cpp.i"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Config.cpp > CMakeFiles/spp-nbody-omp.dir/Config.cpp.i

src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spp-nbody-omp.dir/Config.cpp.s"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurse/kurs00062/je59nuni/ParallelNbody/src/Config.cpp -o CMakeFiles/spp-nbody-omp.dir/Config.cpp.s

# Object files for target spp-nbody-omp
spp__nbody__omp_OBJECTS = \
"CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o" \
"CMakeFiles/spp-nbody-omp.dir/Body.cpp.o" \
"CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o" \
"CMakeFiles/spp-nbody-omp.dir/Config.cpp.o"

# External object files for target spp-nbody-omp
spp__nbody__omp_EXTERNAL_OBJECTS =

../bin/spp-nbody-omp: src/CMakeFiles/spp-nbody-omp.dir/OmpPractical.cpp.o
../bin/spp-nbody-omp: src/CMakeFiles/spp-nbody-omp.dir/Body.cpp.o
../bin/spp-nbody-omp: src/CMakeFiles/spp-nbody-omp.dir/Simulation.cpp.o
../bin/spp-nbody-omp: src/CMakeFiles/spp-nbody-omp.dir/Config.cpp.o
../bin/spp-nbody-omp: src/CMakeFiles/spp-nbody-omp.dir/build.make
../bin/spp-nbody-omp: /usr/lib/gcc/x86_64-redhat-linux/8/libgomp.so
../bin/spp-nbody-omp: /usr/lib64/libpthread.so
../bin/spp-nbody-omp: src/CMakeFiles/spp-nbody-omp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kurse/kurs00062/je59nuni/ParallelNbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../bin/spp-nbody-omp"
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spp-nbody-omp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/spp-nbody-omp.dir/build: ../bin/spp-nbody-omp
.PHONY : src/CMakeFiles/spp-nbody-omp.dir/build

src/CMakeFiles/spp-nbody-omp.dir/clean:
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src && $(CMAKE_COMMAND) -P CMakeFiles/spp-nbody-omp.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/spp-nbody-omp.dir/clean

src/CMakeFiles/spp-nbody-omp.dir/depend:
	cd /home/kurse/kurs00062/je59nuni/ParallelNbody/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kurse/kurs00062/je59nuni/ParallelNbody /home/kurse/kurs00062/je59nuni/ParallelNbody/src /home/kurse/kurs00062/je59nuni/ParallelNbody/build /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src /home/kurse/kurs00062/je59nuni/ParallelNbody/build/src/CMakeFiles/spp-nbody-omp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/spp-nbody-omp.dir/depend
