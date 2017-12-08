#include "GameEngine.h"
#include "core/inc/Log.h"

// initialize global variables
// defined in "core/inc/Globals.h"
bool Globals::quit = false;
const std::string Globals::PATH = "../../../";


GameEngine::GameEngine(std::shared_ptr<InputHandler> inputHandler, const int fps)
  : inputHandler_(inputHandler),
    FPS(fps) {
  log("Starting Game Engine...");

  gameRenderer_ = std::unique_ptr<GameRenderer>(new GameRenderer());

  if (!gameRenderer_->init()) {
    log("Failed to initialize game renderer!");
    Globals::quit = true;
  }

  // create empty inputhandler if none was provided
  if(!inputHandler_) {
    inputHandler_ = std::unique_ptr<InputHandler>(new InputHandler());
  }

  gameController_ = std::unique_ptr<GameController>(new GameController());

  log("Game Engine Started!");
}

GameEngine::GameEngine(const int fps)
  : GameEngine(std::make_shared<InputHandler>(), fps) {
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
  inputHandler_->handleInput();
}

// updates game state
void GameEngine::update() {
  // handle game logic such as spawning new objects and events
  gameController_->frame();

  // handle object movements and collisions
  if (!gameController_->isPaused()) {
    // handle physics
  }
}

// performs all game rendering
void GameEngine::render() {
  if (!gameController_->isLoading()) {
    gameRenderer_->renderFrame(gameController_->getObjects());
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

void GameEngine::addGameObject(std::shared_ptr<GameObject> o) {
  gameController_->addGameObject(o);
}

std::shared_ptr<InputHandler> GameEngine::inputHandler() {
  return inputHandler_;
}
