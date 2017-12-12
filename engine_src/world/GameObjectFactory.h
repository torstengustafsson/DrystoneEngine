#pragma once

#include <memory>

/*
* Singleton class for creating standard game objects.
*/

// forward declarations
class GameObject;

class GameObjectFactory {
public:

  static std::shared_ptr<GameObject> createPlane(const float width, const float height);
  static std::shared_ptr<GameObject> createSmileyFace(const float size);

private:
  GameObjectFactory();

};
