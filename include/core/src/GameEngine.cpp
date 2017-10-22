#include "core/inc/GameEngine.h"

GameEngine::GameEngine(std::shared_ptr<Player> _player)
  : player(_player) {
}

void GameEngine::frame(const std::vector<GameObject*>& gameObjects) {	
  for(auto& o : gameObjects) {
    // TODO
  }
}

bool GameEngine::collision(const std::vector<GameObject*>& gameObjects) {
  for(auto& o : gameObjects) {
    // TODO
  }
	
  return false;
}
