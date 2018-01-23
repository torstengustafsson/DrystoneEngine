#include "GameEngine.h"
#include "core/inc/Globals.h"
#include "components/camera/CameraFactory.h"
#include "core/inc/Log.h"

// initialize global variables
// defined in "core/inc/Globals.h"
bool Globals::quit = false;
const std::string Globals::PATH = "../../../";


GameEngine::GameEngine(InputHandler& _inputHandler, const int fps)
  : GameEngine(fps) {
  inputHandler = _inputHandler;
}

GameEngine::GameEngine(const int fps)
 : FPS(fps) {
  log("Starting Game Engine...");

  addCamera(CameraType::CAM_FPS, true, true);

  if (!gameRenderer.init()) {
    log_verbose("Failed to initialize game renderer!");
    Globals::quit = true;
  }

  log("Game Engine Started!");
}

// perform one in-game frame
void GameEngine::frame() {
  timer = std::chrono::high_resolution_clock::now();
  handleInput();
  update();
  render();
  delayFramerate();
}

// handles user input
void GameEngine::handleInput() {
  inputHandler.handleInput();
}

// updates game state
void GameEngine::update() {
  // handle game logic such as spawning new objects and events
  gameController.frame();

  // handle object movements and collisions
  if (!gameController.isPaused()) {
    // handle physics
  }
}

// performs all game rendering
void GameEngine::render() {
  if (!gameController.isLoading()) {
    gameRenderer.renderFrame();
  }
}

// locks framerate to a fixed value defined by 'FPS'
void GameEngine::delayFramerate() {
  using namespace std::chrono;
  milliseconds frameTimeElapsed = duration_cast<milliseconds>(high_resolution_clock::now() - timer);

  __int64 frameTicks = frameTimeElapsed.count();
  double temp = 1000 / static_cast<double>(FPS);
  const __int64 SCREEN_TICKS_PER_FRAME = static_cast<__int64>(temp);

  if (frameTicks < SCREEN_TICKS_PER_FRAME) {
    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks); // wait remaining time
  }
}

#ifdef EMSCRIPTEN
void GameEngine::main_loop() {
  frame();
}

void GameEngine::run() {
  emscripten_set_main_loop(main_loop, 60, 1);
}
#else
void GameEngine::run() {
  while (!Globals::quit) {
    frame();
  }
}
#endif

void GameEngine::addGameObject(const GameObject& objectPrototype) {
  gameController.addGameObject(objectPrototype);
}

void GameEngine::addCamera(CameraType type, bool mouseLock, bool active) {
  Camera camera(type, ProjectionType::PERSPECTIVE);
  gameController.addCamera(camera);

  if (active) {
    gameRenderer.setActiveCamera(&camera);
  }
}

InputHandler& GameEngine::getInputHandler() {
  return inputHandler;
}
