#pragma once

#include <memory>

/*
* Singleton class for creating standard game objects.
*/

// forward declarations
class GameObject;

class GameObjectFactory {
public:

  static GameObject createPlane(const float width, const float height);

private:
  GameObjectFactory();

};
