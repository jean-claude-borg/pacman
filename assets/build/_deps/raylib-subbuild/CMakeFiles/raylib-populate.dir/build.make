# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\pacman\build\_deps\raylib-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\pacman\build\_deps\raylib-subbuild

# Utility rule file for raylib-populate.

# Include the progress variables for this target.
include CMakeFiles/raylib-populate.dir/progress.make

CMakeFiles/raylib-populate: CMakeFiles/raylib-populate-complete


CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'raylib-populate'"
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-subbuild/CMakeFiles
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/CMakeFiles/raylib-populate-complete
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-done

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'raylib-populate'"
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'raylib-populate'"
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-src
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-build
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/tmp
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E make_directory C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-urlinfo.txt
raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'raylib-populate'"
	cd /d C:\dev\pacman\build\_deps && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -P C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/download-raylib-populate.cmake
	cd /d C:\dev\pacman\build\_deps && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -P C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/verify-raylib-populate.cmake
	cd /d C:\dev\pacman\build\_deps && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -P C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/extract-raylib-populate.cmake
	cd /d C:\dev\pacman\build\_deps && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'raylib-populate'"
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo_append
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'raylib-populate'"
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo_append
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure: raylib-populate-prefix/tmp/raylib-populate-cfgcmd.txt
raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'raylib-populate'"
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'raylib-populate'"
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'raylib-populate'"
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\dev\pacman\build\_deps\raylib-build && "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E touch C:/dev/pacman/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test

raylib-populate: CMakeFiles/raylib-populate
raylib-populate: CMakeFiles/raylib-populate-complete
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test
raylib-populate: CMakeFiles/raylib-populate.dir/build.make

.PHONY : raylib-populate

# Rule to build all files generated by this target.
CMakeFiles/raylib-populate.dir/build: raylib-populate

.PHONY : CMakeFiles/raylib-populate.dir/build

CMakeFiles/raylib-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\raylib-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/raylib-populate.dir/clean

CMakeFiles/raylib-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\dev\pacman\build\_deps\raylib-subbuild C:\dev\pacman\build\_deps\raylib-subbuild C:\dev\pacman\build\_deps\raylib-subbuild C:\dev\pacman\build\_deps\raylib-subbuild C:\dev\pacman\build\_deps\raylib-subbuild\CMakeFiles\raylib-populate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raylib-populate.dir/depend

