#include "core/GameController.h"
#include "components/ComponentManager.h"
#include "core/inc/Log.h"

#include <algorithm>

GameController::GameController() {
  log("Game Controller Created!");
}

void GameController::frame() {
  for (auto object : objects) {
    object.runEventHandlers();
  }
}

void GameController::addGameObject(const GameObject& objectPrototype) {
  GameObject object = ComponentManager::addGameObject(objectPrototype);
  objects.push_back(object);
}

void GameController::removeGameObject(const GameObject& object) {
  objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
  ComponentManager::removeGameObject(object.getIndex());
}

void GameController::addCamera(const Camera& camera) {
  cameras.push_back(camera);
}

void GameController::removeCamera(const Camera& camera) {
  //cameras.erase(std::remove(cameras.begin(), cameras.end(), camera), cameras.end());
}

std::vector<GameObject> GameController::getObjects() {
  return objects;
}

bool GameController::isPaused() {
  return gamePaused;
}

bool GameController::isLoading() {
  return loading;
}
