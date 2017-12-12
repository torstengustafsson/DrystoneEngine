#include "core/GameRenderer.h"
#include "world/GameObject.h"
#include "core/inc/Log.h"

GameRenderer::~GameRenderer() {
  close();
}

void GameRenderer::close() {
  //Quit SDL subsystems
  SDL_GL_DeleteContext(mainContext);
  IMG_Quit();
  SDL_Quit();
}

bool GameRenderer::init() {
  log("Initializing Game Renderer...");

  // initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    log("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    return false;
  }

  // create window
  gameWindow = std::unique_ptr<SDL_Window, sdl_deleter>(
    SDL_CreateWindow(programName.c_str(),
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     SCREEN_WIDTH,
                     SCREEN_HEIGHT,
                     SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE),
    sdl_deleter()
  );

  if( gameWindow == NULL ) {
    log("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
    return false;
  }

  // create opengl context and attach it to game window
  mainContext = SDL_GL_CreateContext(gameWindow.get());

  printOpenGlInfo();

  setOpenGLAttributes();

  // syncronize buffer swap with the monitor's vertical refresh
  SDL_GL_SetSwapInterval(1);

  // init GLEW
  glewExperimental = GL_TRUE;
  glewInit();

  // set and initialize window
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(gameWindow.get());

  //initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
    log("SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError()));
    return false;
  }

  // initialize SDL_ttf
  if( TTF_Init() == -1 ) {
    log("SDL_ttf could not initialize! SDL_ttf Error: " + std::string(TTF_GetError()));
    return false;
  }

  log("Game Renderer Initialized!");
  return true;
}

bool GameRenderer::setOpenGLAttributes()
{
  // Set our OpenGL version.
  // SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  // 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  // Turn on double buffering with a 24bit Z buffer.
  // You may need to change this to 16 or 32 for your system
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  return true;
}

int GameRenderer::getWidth() {
	return SCREEN_WIDTH;
}

int GameRenderer::getHeight() {
	return SCREEN_HEIGHT;
}

void GameRenderer::renderFrame(std::vector<std::shared_ptr<GameObject>> gameObjects) {
  SCREEN_WIDTH = SDL_GetWindowSurface(gameWindow.get())->w;
  SCREEN_HEIGHT = SDL_GetWindowSurface(gameWindow.get())->h;
  glClear(GL_COLOR_BUFFER_BIT);

  // render objects to screen
  for(auto o : gameObjects) {
    renderObject(o);
  }

  // update screen
  SDL_GL_SwapWindow(gameWindow.get());

}

void GameRenderer::renderObject(std::shared_ptr<GameObject> o) {
  const linalg::Mat4 worldOrigin; // identity matrix
  o->render(worldOrigin, gameCamera->getView(), gameCamera->getProjection());
}

void GameRenderer::printOpenGlInfo() {
  std::string message = "\nOpenGL Info:\n";
  char* openGlVersion = (char*)glGetString(GL_VERSION);
  char* shaderVersion = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
//printf(openGlVersion);
  message += "  - OpenGL version: " + std::string(openGlVersion) + "\n";
  message += "  - GLSL version: " + std::string(shaderVersion) + "\n";
  log(message);
}