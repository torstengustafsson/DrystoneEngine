#include "core/inc/GameController.h"

GameController::GameController(std::shared_ptr<Player> _player)
  : player(_player) {

  inputHandler = std::unique_ptr<InputHandler>(new InputHandler(player));
}

void GameController::frame() {	
  if(!gamePaused && !loading) {

    //handle keyboard input
    inputHandler->handleInput();
  }
}

// Returns a vector containing the objects close enough to player to fit the screen.
std::vector<GameObject*> GameController::getObjects() {
  // TODO: return subset of all objects instead
  return objectList;
}

bool GameController::isPaused() {
  return gamePaused;
}

bool GameController::isLoading() {
  return loading;
}
