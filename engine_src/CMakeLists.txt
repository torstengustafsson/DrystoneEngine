cmake_minimum_required(VERSION 3.7)

project(DrystoneEngine)

# specify source files
file(GLOB_RECURSE CPP_FILES "*.cpp")

# specify header files
file(GLOB_RECURSE HEADER_FILES "*.h")


### STRUCTURE SOURCE FILES ###

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
GroupSources("core")
GroupSources("datastructures")
GroupSources("input")
GroupSources("linalg")
GroupSources("opengl")
GroupSources("world")

# Source main files manually
source_group(core FILES GameEngine.cpp)
source_group(core FILES GameEngine.h)

### END STRUCTURE SOURCE FILES ###


# specify include directory
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

add_library(${PROJECT_NAME} ${CPP_FILES}
                            ${HEADER_FILES})

set(EXT_LIBRARIES ${OPENGL_LIBRARIES}
                  ${SDL2_LIBRARIES}
                  ${SDL2_IMAGE_LIBRARIES}
                  ${SDL2_TTF_LIBRARIES}
                  ${GLEW_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ${EXT_LIBRARIES})

# Expose the definitions to other subprojects through cache variable.
set(${PROJECT_NAME}_DEFINITIONS ${EXT_LIBRARIES}
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)

# Expose public includes to other subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_INCLUDE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
