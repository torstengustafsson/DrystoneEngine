#include "core/inc/Game.h"


Game::Game() {

  gameRenderer = std::unique_ptr<GameRenderer>(new GameRenderer());

  if(!gameRenderer->init()) {
    printf( "Failed to initialize game renderer!\n" );
    return;
  }

  player = std::shared_ptr<Player>(new Player("player"));

  inputHandler = std::unique_ptr<InputHandler>(new InputHandler());
  camera = std::unique_ptr<Camera>(new Camera(player));
  gameController = std::unique_ptr<GameController>(new GameController(player));
  gameEngine = std::unique_ptr<GameEngine>(new GameEngine(player));
}

// perform one in-game frame
void Game::frame() {
  timer = std::chrono::high_resolution_clock::now();

  handleInput();
  update();
  render();
  delay(std::chrono::high_resolution_clock::now() - timer);  
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
void Game::delay(std::chrono::nanoseconds frameTimeElapsed) {
  int frameTicks = frameTimeElapsed.count();
  const int SCREEN_TICKS_PER_FRAME = 1000 / static_cast<float>(FPS);

  if (frameTicks < SCREEN_TICKS_PER_FRAME) {
    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks); // wait remaining time
  }
}