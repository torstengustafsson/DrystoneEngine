#include "core/GameController.h"
#include "core\inc\Log.h"

GameController::GameController() {
  log("Game Controller Created!");
}

void GameController::frame() {	

}

void GameController::addGameObject(std::shared_ptr<GameObject> o) {
  objectList.push_back(o);
}

void GameController::removeGameObject(std::shared_ptr<GameObject> o) {
  // TODO
}

// Returns a vector containing the objects close enough to player to fit the screen.
std::vector<std::shared_ptr<GameObject>> GameController::getObjects() {
  // TODO: return subset of all objects instead
  return objectList;
}

bool GameController::isPaused() {
  return gamePaused;
}

bool GameController::isLoading() {
  return loading;
}
