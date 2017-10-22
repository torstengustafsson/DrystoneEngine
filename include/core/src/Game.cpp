#include "core/inc/Game.h"


Game::Game() {

  gameRenderer = std::unique_ptr<GameRenderer>(new GameRenderer());

  if(!gameRenderer->init()) {
    printf( "Failed to initialize game renderer!\n" );
    return;
  }

  player = std::shared_ptr<Player>(new Player("player"));

  inputHandler = std::unique_ptr<InputHandler>(new InputHandler(player));
  camera = std::unique_ptr<Camera>(new Camera(player));
  gameController = std::unique_ptr<GameController>(new GameController(player));
  gameEngine = std::unique_ptr<GameEngine>(new GameEngine(player));
}

// perform one in-game frame
void Game::frame() {
  handleInput();
  update();
  render();
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
