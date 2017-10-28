#pragma once

#include <vector>
#include <memory>
#include <cmath>
#include "world/GameObject.h"

/*
* TODO: write description
*/

class GameEngine {
public:
  GameEngine();
	
  void frame(const std::vector<GameObject*>& gameObjects);

private:
  bool collision(const std::vector<GameObject*>& gameObjects);
};
