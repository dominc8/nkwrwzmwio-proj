# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projekt_drzewo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projekt_drzewo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projekt_drzewo.dir/flags.make

CMakeFiles/projekt_drzewo.dir/main.cpp.obj: CMakeFiles/projekt_drzewo.dir/flags.make
CMakeFiles/projekt_drzewo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projekt_drzewo.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\projekt_drzewo.dir\main.cpp.obj -c C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\main.cpp

CMakeFiles/projekt_drzewo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt_drzewo.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\main.cpp > CMakeFiles\projekt_drzewo.dir\main.cpp.i

CMakeFiles/projekt_drzewo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt_drzewo.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\main.cpp -o CMakeFiles\projekt_drzewo.dir\main.cpp.s

# Object files for target projekt_drzewo
projekt_drzewo_OBJECTS = \
"CMakeFiles/projekt_drzewo.dir/main.cpp.obj"

# External object files for target projekt_drzewo
projekt_drzewo_EXTERNAL_OBJECTS =

projekt_drzewo.exe: CMakeFiles/projekt_drzewo.dir/main.cpp.obj
projekt_drzewo.exe: CMakeFiles/projekt_drzewo.dir/build.make
projekt_drzewo.exe: CMakeFiles/projekt_drzewo.dir/linklibs.rsp
projekt_drzewo.exe: CMakeFiles/projekt_drzewo.dir/objects1.rsp
projekt_drzewo.exe: CMakeFiles/projekt_drzewo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable projekt_drzewo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\projekt_drzewo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projekt_drzewo.dir/build: projekt_drzewo.exe

.PHONY : CMakeFiles/projekt_drzewo.dir/build

CMakeFiles/projekt_drzewo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\projekt_drzewo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/projekt_drzewo.dir/clean

CMakeFiles/projekt_drzewo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\cmake-build-debug C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\cmake-build-debug C:\Users\eitowiec\Desktop\01_eit_1_sem_mgr\04_NkwRWZMWIO\projekt_drzewo\01_generator\cmake-build-debug\CMakeFiles\projekt_drzewo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projekt_drzewo.dir/depend
