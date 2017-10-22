#include "core/inc/GameController.h"

GameController::GameController(std::shared_ptr<Player> _player)
  : player(_player) {


}

void GameController::frame() {	

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
