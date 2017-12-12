#pragma once

#include "world/GameObject.h"

#include <memory>

/*
* Singleton class for creating standard game objects.
*/

class GameObjectFactory {
public:

  static std::shared_ptr<GameObject> createPlane(const float width, const float height);

private:
  GameObjectFactory();

};
