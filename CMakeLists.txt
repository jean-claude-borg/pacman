cmake_minimum_required(VERSION 3.15)
project(pacman)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static")
set(CMAKE_C_STANDARD 11)
option(SUPPORT_FILEFORMAT_BMP ON)

# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

    # build raylib
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

  endif()

endif()

add_executable(pacman main.c save.c)
target_link_libraries(pacman raylib)