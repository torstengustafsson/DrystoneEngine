#pragma once

#include <memory>

/*
* Singleton class for creating standard game objects.
* creates prototypes of game objects which, when activated by the game engine 
* will turn into identical, activated game objects (prototype objects do not 
* have index values set).
*/

// forward declarations
class GameObject;

class GameObjectFactory {
public:

  static GameObject createPlane(const float width, const float height);

private:
  GameObjectFactory();

};
