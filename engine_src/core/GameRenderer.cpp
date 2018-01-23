#include "core/GameRenderer.h"
#include "components/ComponentManager.h"
#include "components/Mesh.h"
#include "core/inc/Log.h"

GameRenderer::GameRenderer() {
  meshes = ComponentManager::getMeshArray();
}

GameRenderer::~GameRenderer() {
  close();
}

void GameRenderer::setActiveCamera(const Camera* camera) {
  activeCamera = camera;
}

void GameRenderer::close() {
  //Quit SDL subsystems
  SDL_GL_DeleteContext(mainContext);
  SDL_Quit();
}

bool GameRenderer::init() {
  log("Initializing Game Renderer...");

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
  setSDLAttributes();
  initOpenGL();

  // TODO: use SDL version, or other more OpenGL friendly variant?
  ////initialize PNG loading
  //int imgFlags = IMG_INIT_PNG;
  //if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
  //  log("SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError()));
  //  return false;
  //}

  //// initialize SDL_ttf
  //if( TTF_Init() == -1 ) {
  //  log("SDL_ttf could not initialize! SDL_ttf Error: " + std::string(TTF_GetError()));
  //  return false;
  //}

  log("Game Renderer Initialized!");
  return true;
}

void GameRenderer::setSDLAttributes() {
  // Set OpenGL version.
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  // Turn on double buffering with a 24 bit Z buffer.
  // May need to be changed to 16 or 32 bits
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  // syncronize buffer swap with the monitor's vertical refresh
  SDL_GL_SetSwapInterval(1);

  SDL_GL_SwapWindow(gameWindow.get());
}

void GameRenderer::initOpenGL() {
  // init GLEW
  glewExperimental = GL_TRUE;
  glewInit();

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

  // set and initialize window
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int GameRenderer::getWidth() {
	return SCREEN_WIDTH;
}

int GameRenderer::getHeight() {
	return SCREEN_HEIGHT;
}

void GameRenderer::renderFrame() {

  if (activeCamera == nullptr) {
    return;
  }

  SCREEN_WIDTH = SDL_GetWindowSurface(gameWindow.get())->w;
  SCREEN_HEIGHT = SDL_GetWindowSurface(gameWindow.get())->h;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // render objects to screen
  for(int i = 0; i < ComponentManager::getNumObjects(); i++) {
    meshes[i].render(activeCamera->getView(), activeCamera->getProjection());
  }

  // update screen
  SDL_GL_SwapWindow(gameWindow.get());

}

void GameRenderer::printOpenGlInfo() {
  std::string message = "\nOpenGL Info:\n";
  char* openGlVersion = (char*)glGetString(GL_VERSION);
  char* shaderVersion = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

  message += "  - OpenGL version: " + std::string(openGlVersion) + "\n";
  message += "  - GLSL version: " + std::string(shaderVersion) + "\n";
  log(message);
}

void GameRenderer::hideMouseCursor() {
  // TODO
}

void GameRenderer::setMousePos(const int x, const int y) {
 SDL_WarpMouseInWindow(gameWindow.get(), x, y);
}
