# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\pacman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\pacman\build

# Include any dependencies generated for this target.
include _deps/raylib-build/raylib/CMakeFiles/raylib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/raylib-build/raylib/CMakeFiles/raylib.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj: _deps/raylib-src/src/core.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj -MF CMakeFiles\raylib.dir\core.c.obj.d -o CMakeFiles\raylib.dir\core.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\core.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/core.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\core.c > CMakeFiles\raylib.dir\core.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/core.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\core.c -o CMakeFiles\raylib.dir\core.c.s

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj: _deps/raylib-src/src/models.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj -MF CMakeFiles\raylib.dir\models.c.obj.d -o CMakeFiles\raylib.dir\models.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\models.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/models.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\models.c > CMakeFiles\raylib.dir\models.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/models.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\models.c -o CMakeFiles\raylib.dir\models.c.s

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj: _deps/raylib-src/src/shapes.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj -MF CMakeFiles\raylib.dir\shapes.c.obj.d -o CMakeFiles\raylib.dir\shapes.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\shapes.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/shapes.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\shapes.c > CMakeFiles\raylib.dir\shapes.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/shapes.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\shapes.c -o CMakeFiles\raylib.dir\shapes.c.s

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj: _deps/raylib-src/src/text.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj -MF CMakeFiles\raylib.dir\text.c.obj.d -o CMakeFiles\raylib.dir\text.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\text.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/text.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\text.c > CMakeFiles\raylib.dir\text.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/text.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\text.c -o CMakeFiles\raylib.dir\text.c.s

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj: _deps/raylib-src/src/textures.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj -MF CMakeFiles\raylib.dir\textures.c.obj.d -o CMakeFiles\raylib.dir\textures.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\textures.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/textures.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\textures.c > CMakeFiles\raylib.dir\textures.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/textures.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\textures.c -o CMakeFiles\raylib.dir\textures.c.s

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj: _deps/raylib-src/src/utils.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj -MF CMakeFiles\raylib.dir\utils.c.obj.d -o CMakeFiles\raylib.dir\utils.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\utils.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/utils.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\utils.c > CMakeFiles\raylib.dir\utils.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/utils.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\utils.c -o CMakeFiles\raylib.dir\utils.c.s

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/flags.make
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/includes_C.rsp
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj: _deps/raylib-src/src/raudio.c
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object _deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj -MF CMakeFiles\raylib.dir\raudio.c.obj.d -o CMakeFiles\raylib.dir\raudio.c.obj -c C:\dev\pacman\build\_deps\raylib-src\src\raudio.c

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/raudio.c.i"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\dev\pacman\build\_deps\raylib-src\src\raudio.c > CMakeFiles\raylib.dir\raudio.c.i

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/raudio.c.s"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\dev\pacman\build\_deps\raylib-src\src\raudio.c -o CMakeFiles\raylib.dir\raudio.c.s

# Object files for target raylib
raylib_OBJECTS = \
"CMakeFiles/raylib.dir/core.c.obj" \
"CMakeFiles/raylib.dir/models.c.obj" \
"CMakeFiles/raylib.dir/shapes.c.obj" \
"CMakeFiles/raylib.dir/text.c.obj" \
"CMakeFiles/raylib.dir/textures.c.obj" \
"CMakeFiles/raylib.dir/utils.c.obj" \
"CMakeFiles/raylib.dir/raudio.c.obj"

# External object files for target raylib
raylib_EXTERNAL_OBJECTS = \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/context.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/init.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/input.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/monitor.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/vulkan.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/window.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_init.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_joystick.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_monitor.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_time.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_thread.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_window.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/wgl_context.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/egl_context.c.obj" \
"C:/dev/pacman/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/osmesa_context.c.obj"

_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/core.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/models.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/shapes.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/text.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/textures.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/utils.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/raudio.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/context.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/init.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/input.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/monitor.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/vulkan.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/window.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_init.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_joystick.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_monitor.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_time.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_thread.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/win32_window.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/wgl_context.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/egl_context.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/glfw_objlib.dir/osmesa_context.c.obj
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/build.make
_deps/raylib-build/raylib/libraylib.a: _deps/raylib-build/raylib/CMakeFiles/raylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\dev\pacman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C static library libraylib.a"
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && $(CMAKE_COMMAND) -P CMakeFiles\raylib.dir\cmake_clean_target.cmake
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\raylib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/raylib-build/raylib/CMakeFiles/raylib.dir/build: _deps/raylib-build/raylib/libraylib.a
.PHONY : _deps/raylib-build/raylib/CMakeFiles/raylib.dir/build

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/clean:
	cd /d C:\dev\pacman\build\_deps\raylib-build\raylib && $(CMAKE_COMMAND) -P CMakeFiles\raylib.dir\cmake_clean.cmake
.PHONY : _deps/raylib-build/raylib/CMakeFiles/raylib.dir/clean

_deps/raylib-build/raylib/CMakeFiles/raylib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\dev\pacman C:\dev\pacman\build\_deps\raylib-src\src C:\dev\pacman\build C:\dev\pacman\build\_deps\raylib-build\raylib C:\dev\pacman\build\_deps\raylib-build\raylib\CMakeFiles\raylib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/raylib-build/raylib/CMakeFiles/raylib.dir/depend

