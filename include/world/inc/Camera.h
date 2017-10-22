#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "GameObject.h"

/*
* TODO: write description
*/

class Camera {
public:
  Camera(std::shared_ptr<Player> player);

private:
  std::shared_ptr<Player> player;
};
