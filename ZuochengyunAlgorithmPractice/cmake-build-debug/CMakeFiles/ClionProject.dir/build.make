# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ClionProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClionProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClionProject.dir/flags.make

CMakeFiles/ClionProject.dir/main.cpp.obj: CMakeFiles/ClionProject.dir/flags.make
CMakeFiles/ClionProject.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClionProject.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ClionProject.dir\main.cpp.obj -c C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\main.cpp

CMakeFiles/ClionProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClionProject.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\main.cpp > CMakeFiles\ClionProject.dir\main.cpp.i

CMakeFiles/ClionProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClionProject.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\main.cpp -o CMakeFiles\ClionProject.dir\main.cpp.s

CMakeFiles/ClionProject.dir/base_class-1.cpp.obj: CMakeFiles/ClionProject.dir/flags.make
CMakeFiles/ClionProject.dir/base_class-1.cpp.obj: ../base_class-1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ClionProject.dir/base_class-1.cpp.obj"
	C:\PROGRA~1\JETBRA~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ClionProject.dir\base_class-1.cpp.obj -c C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\base_class-1.cpp

CMakeFiles/ClionProject.dir/base_class-1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClionProject.dir/base_class-1.cpp.i"
	C:\PROGRA~1\JETBRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\base_class-1.cpp > CMakeFiles\ClionProject.dir\base_class-1.cpp.i

CMakeFiles/ClionProject.dir/base_class-1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClionProject.dir/base_class-1.cpp.s"
	C:\PROGRA~1\JETBRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\base_class-1.cpp -o CMakeFiles\ClionProject.dir\base_class-1.cpp.s

# Object files for target ClionProject
ClionProject_OBJECTS = \
"CMakeFiles/ClionProject.dir/main.cpp.obj" \
"CMakeFiles/ClionProject.dir/base_class-1.cpp.obj"

# External object files for target ClionProject
ClionProject_EXTERNAL_OBJECTS =

ClionProject.exe: CMakeFiles/ClionProject.dir/main.cpp.obj
ClionProject.exe: CMakeFiles/ClionProject.dir/base_class-1.cpp.obj
ClionProject.exe: CMakeFiles/ClionProject.dir/build.make
ClionProject.exe: CMakeFiles/ClionProject.dir/linklibs.rsp
ClionProject.exe: CMakeFiles/ClionProject.dir/objects1.rsp
ClionProject.exe: CMakeFiles/ClionProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ClionProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ClionProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClionProject.dir/build: ClionProject.exe

.PHONY : CMakeFiles/ClionProject.dir/build

CMakeFiles/ClionProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ClionProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ClionProject.dir/clean

CMakeFiles/ClionProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug C:\Users\Gavyn\Desktop\ClionProject\AlgorithmPractice\cmake-build-debug\CMakeFiles\ClionProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClionProject.dir/depend
