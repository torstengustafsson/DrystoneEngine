#include "core/inc/Game.h"


Game::Game() {

  gameRenderer = std::unique_ptr<GameRenderer>(new GameRenderer());

  if(!gameRenderer->init()) {
    printf( "Failed to initialize game renderer!\n" );
    return;
  }

  player = std::shared_ptr<Player>(new Player("player"));

  camera = std::unique_ptr<Camera>(new Camera(player));
  gameController = std::unique_ptr<GameController>(new GameController(player));
  gameEngine = std::unique_ptr<GameEngine>(new GameEngine(player));
}

// perform one in-game frame
void Game::frame() {
  //Handle game logic such as spawning new objects and events
  gameController->frame();

  //Handle object movements and collisions
  if (!gameController->isPaused()) {
	  gameEngine->frame(gameController->getObjects());
  }

  //Render scene
  if (!gameController->isLoading())
	  gameRenderer->renderFrame(gameController->getObjects());
}
