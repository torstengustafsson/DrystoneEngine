cmake_minimum_required(VERSION 3.7)

project(DrystoneEngineProjects)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

set(ROOT_DIR ${PROJECT_SOURCE_DIR})

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

# Remove 'lib' prefix for shared libraries on Windows
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()

# add OpenGL
find_package(OpenGL REQUIRED)

# add SDL2 packages
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/ext/SDL2/SDL2-2.0.7)
set(SDL2_image_DIR ${CMAKE_SOURCE_DIR}/ext/SDL2/SDL2_image-2.0.2)
set(SDL2_ttf_DIR ${CMAKE_SOURCE_DIR}/ext/SDL2/SDL2_ttf-2.0.14)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

#add glew
set(CMAKE_PREFIX_PATH  "${CMAKE_SOURCE_DIR}/ext/glew-2.1.0")
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(CMAKE_LIBRARY_PATH  "${CMAKE_SOURCE_DIR}/ext/glew-2.1.0/lib/Release/x64/")
else ()
  set(CMAKE_LIBRARY_PATH  "${CMAKE_SOURCE_DIR}/ext/glew-2.1.0/lib/Release/Win32/")
endif ()
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${CMAKE_PREFIX_PATH}/include)

# add game engine
add_subdirectory(engine_src)

# add demos
add_subdirectory(demos/rgb_game)
add_subdirectory(demos/geometry_game)
