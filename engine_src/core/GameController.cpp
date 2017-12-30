#include "core/GameController.h"
#include "components/ComponentManager.h"
#include "core/inc/Log.h"

#include <algorithm>

GameController::GameController() {
  log("Game Controller Created!");
}

void GameController::frame() {
  for (auto gameObject : gameObjects) {
    gameObject.runEventHandlers();
  }
}

void GameController::addGameObject(const GameObject& objectPrototype) {
  GameObject gameObject = ComponentManager::addGameObject(objectPrototype);
  gameObjects.push_back(gameObject);
}

void GameController::removeGameObject(const GameObject& gameObject) {
  gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
  ComponentManager::removeGameObject(gameObject.getIndex());
}

std::vector<GameObject> GameController::getObjects() {
  return gameObjects;
}

bool GameController::isPaused() {
  return gamePaused;
}

bool GameController::isLoading() {
  return loading;
}
