#include "core/Game.h"
#include "core/inc/Globals.h"

// initialize global variables
// defined in "core/inc/Globals.h"
bool Globals::quit = false;

Game::Game(const int fps)
  : FPS(fps) {

  gameRenderer = std::unique_ptr<GameRenderer>(new GameRenderer());

  if (!gameRenderer->init()) {
    printf("Failed to initialize game renderer!\n");
    Globals::quit = true;
  }

  inputHandler = std::unique_ptr<InputHandler>(new InputHandler());
  gameController = std::unique_ptr<GameController>(new GameController());
  gameEngine = std::unique_ptr<GameEngine>(new GameEngine());
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
  inputHandler->handleInput();
}

// updates game state
void Game::update() {
  // handle game logic such as spawning new objects and events
  gameController->frame();

  // handle object movements and collisions
  if (!gameController->isPaused()) {
    gameEngine->frame(gameController->getObjects());
  }
}

// performs all game rendering
void Game::render() {
  if (!gameController->isLoading()) {
    gameRenderer->renderFrame(gameController->getObjects());
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