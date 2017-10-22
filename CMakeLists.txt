cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME SDL2_OpenGL)

project(${PROJECT_NAME})
find_package(OpenGL REQUIRED)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

 # set the default path for built executables to the "bin" directory
 set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

 # set the default path for built libraries to the "lib" directory
 set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

 # specify include directory
 set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# specify external dependencies directory
set(EXT_DIR ${PROJECT_SOURCE_DIR}/ext)

include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

# include external dependencies
include_directories("${EXT_DIR}/SDL2/SDL2_image-2.0.1/include")
include_directories("${EXT_DIR}/SDL2/SDL2-2.0.5/include")
include_directories("${EXT_DIR}/SDL2/SDL2_ttf-2.0.14/include")
include_directories("${EXT_DIR}/glew-2.1.0/include")
set(EXT_LIBRARIES
      ${EXT_DIR}/SDL2/SDL2-2.0.5/lib/x64/SDL2.lib
      ${EXT_DIR}/SDL2/SDL2-2.0.5/lib/x64/SDL2main.lib
      ${EXT_DIR}/SDL2/SDL2_ttf-2.0.14/lib/x64/SDL2_ttf.lib
      ${EXT_DIR}/SDL2/SDL2_image-2.0.1/lib/x64/SDL2_image.lib
      ${EXT_DIR}/glew-2.1.0/lib/Release/x64/glew32s.lib )


# Bump up warning levels appropriately for clang, gcc & msvc and build in debug mode
if (MSVC)
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

# Add source files
set( PROJECT_SOURCE_FILES
       include/main.cpp )

# Add header files
file(GLOB_RECURSE HEADER_FILES "*.h")


# The below macro was shamelessly stolen from:
# https://cmake.org/pipermail/cmake/2013-November/056336.html

# Organize the files in visual studio folders, according to 
# the organization in the file systems
macro(GroupSources curdir)
  file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)
  foreach(child ${children})
    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
      GroupSources(${curdir}/${child})
    else()
      string(REPLACE "/" "\\" groupname ${curdir})
      source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
    endif()
  endforeach()
endmacro()

# Execute the macro
GroupSources("include")


#if (NOT ${PROJECT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
#  file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#endif()

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${EXT_LIBRARIES})
