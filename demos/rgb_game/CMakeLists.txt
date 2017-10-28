cmake_minimum_required(VERSION 3.7)

project(Demo_Input)

file(GLOB_RECURSE CPP_FILES *.cpp)
file(GLOB_RECURSE HEADER_FILES "*.h")

add_executable(${PROJECT_NAME} ${CPP_FILES}
                               ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC DrystoneEngine)
target_include_directories(${PROJECT_NAME} PUBLIC ${DrystoneEngine_INCLUDE_DIRS})


# copy .dll:s to .exe folder on build

macro(AddDll dllpath)
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD       # Adds a post-build event to MyTest
      COMMAND ${CMAKE_COMMAND} -E copy_if_different          # which executes "cmake - E copy_if_different..."
              ${ROOT_DIR}/ext/${dllpath}                 # <--this is in-file
              $<TARGET_FILE_DIR:${PROJECT_NAME}>)                # <--this is out-file path
endmacro()

set(CMAKE_PREFIX_PATH  "${CMAKE_SOURCE_DIR}/ext/glew-2.1.0")
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  AddDll("SDL2/SDL2-2.0.7/lib/x64/SDL2.dll")               # SDL2
  AddDll("SDL2/SDL2_image-2.0.2/lib/x64/libjpeg-9.dll")    # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x64/libpng16-16.dll")  # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x64/libtiff-5.dll")    # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x64/libwebp-7.dll")    # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x64/SDL2_image.dll")   # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x64/zlib1.dll")        # SDL2_image
  AddDll("SDL2/SDL2_ttf-2.0.14/lib/x64/libfreetype-6.dll") # SDL2_ttf
  AddDll("SDL2/SDL2_ttf-2.0.14/lib/x64/SDL2_ttf.dll")      # SDL2_ttf
  AddDll("glew-2.1.0/bin/Release/x64/glew32.dll")          # GLEW
else ()
  AddDll("SDL2/SDL2-2.0.7/lib/x86/SDL2.dll")               # SDL2
  AddDll("SDL2/SDL2_image-2.0.2/lib/x86/libjpeg-9.dll")    # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x86/libpng16-16.dll")  # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x86/libtiff-5.dll")    # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x86/libwebp-7.dll")    # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x86/SDL2_image.dll")   # SDL2_image
  AddDll("SDL2/SDL2_image-2.0.2/lib/x86/zlib1.dll")        # SDL2_image
  AddDll("SDL2/SDL2_ttf-2.0.14/lib/x86/libfreetype-6.dll") # SDL2_ttf
  AddDll("SDL2/SDL2_ttf-2.0.14/lib/x86/SDL2_ttf.dll")      # SDL2_ttf
  AddDll("glew-2.1.0/bin/Release/Win32/glew32.dll")        # GLEW
endif ()

