#pragma once

#include <vector>
#include <memory>
#include <cmath>
#include "world/inc/GameObject.h"
#include "world/inc/Player.h"

/*
* TODO: write description
*/

class GameEngine {
public:
  GameEngine(std::shared_ptr<Player> _player);
	
  void frame(const std::vector<GameObject*>& gameObjects);

private:
  std::shared_ptr<Player> player;
  bool collision(const std::vector<GameObject*>& gameObjects);
};
