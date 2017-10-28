#include "core/Game.h"

// initialize global variables
// defined in "core/inc/Globals.h"
bool Globals::quit = false;

Game::Game(std::shared_ptr<InputHandler> inputHandler, const int fps)
  : inputHandler_(inputHandler),
    FPS(fps) {

  gameRenderer_ = std::unique_ptr<GameRenderer>(new GameRenderer());

  if (!gameRenderer_->init()) {
    printf("Failed to initialize game renderer!\n");
    Globals::quit = true;
  }

  // create empty inputhandler if none was provided
  if(!inputHandler_) {
    inputHandler_ = std::unique_ptr<InputHandler>(new InputHandler());
  }

  gameController_ = std::unique_ptr<GameController>(new GameController());
  gameEngine_ = std::unique_ptr<GameEngine>(new GameEngine());
}

Game::Game(InputHandler& _inputHandler, const int fps)
  : Game(std::shared_ptr<InputHandler>(&_inputHandler), fps) {
}

// perform one in-game frame
void Game::frame() {
  timer = std::chrono::high_resolution_clock::now();
  handleInput();
  update();
  render();
  delayFramerate();
}

// handles user input
void Game::handleInput() {
  inputHandler_->handleInput();
}

// updates game state
void Game::update() {
  // handle game logic such as spawning new objects and events
  gameController_->frame();

  // handle object movements and collisions
  if (!gameController_->isPaused()) {
    gameEngine_->frame(gameController_->getObjects());
  }
}

// performs all game rendering
void Game::render() {
  if (!gameController_->isLoading()) {
    gameRenderer_->renderFrame(gameController_->getObjects());
  }
}

// locks framerate to a fixed value defined by 'FPS'
void Game::delayFramerate() {
  using namespace std::chrono;
  milliseconds frameTimeElapsed = duration_cast<milliseconds>(high_resolution_clock::now() - timer);

  __int64 frameTicks = frameTimeElapsed.count();
  double temp = 1000 / static_cast<double>(FPS);
  const __int64 SCREEN_TICKS_PER_FRAME = static_cast<__int64>(temp);

  if (frameTicks < SCREEN_TICKS_PER_FRAME) {
    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks); // wait remaining time
  }
}

std::shared_ptr<InputHandler> Game::inputHandler() {
  return inputHandler_;
}
