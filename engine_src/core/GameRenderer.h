#pragma once

#include "core/inc/sdl_deleter.h"
#include "core/Camera/Camera3D.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "GL/glew.h"

#include <vector>
#include <memory>

/*
* TODO: write description
*/

// forward declarations
class Mesh;

class GameRenderer {
public:
  GameRenderer();
  ~GameRenderer();
	
  int getWidth();
  int getHeight();
	
  bool init();
  void close();
	
  void renderFrame();

  void printOpenGlInfo();

private:
  bool setOpenGLAttributes();

  std::unique_ptr<SDL_Window, sdl_deleter> gameWindow;
  std::shared_ptr<Camera3D> gameCamera;

  // OpenGL context handle
  SDL_GLContext mainContext;

  std::string programName = "SDL2_OpenGL";
  int SCREEN_WIDTH = 800;
  int SCREEN_HEIGHT = 600;

  Mesh* meshes;
};
