#pragma once

#include <vector>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "GL/glew.h"
#include "sdl_deleter.h"
#include "world/inc/GameObject.h"

/*
* TODO: write description
*/

class GameRenderer {
public:
  GameRenderer() = default;
  ~GameRenderer();
	
  int get_width();
  int get_height();
	
  bool init();
  void close();
	
  void renderFrame(std::vector<GameObject*> v);
  void renderObject(GameObject* o);

private:
  bool setOpenGLAttributes();

  std::unique_ptr<SDL_Window, sdl_deleter> gameWindow;
  
  // OpenGL context handle
  SDL_GLContext mainContext;

  std::string programName = "SDL2_OpenGL";
  int SCREEN_WIDTH = 800;
  int SCREEN_HEIGHT = 600;
};
