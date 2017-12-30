#pragma once 

#include "components/Mesh.h"
#include "components/Collider.h"

/*
* Singleton class.
* 
* Manages all GameObject components. The actual objects are stored here, and each GameObject 
* holds references to its individual components.
* This allows for better performance in the game loop, as it can loop through arrays of data, 
* instead of looping through pointers to data.
*/

// forward declarations
class GameObject;

#define MAX_GAMEOBJECTS 1000

class ComponentManager {
public:
  static GameObject addGameObject(const GameObject& objectPrototype);
  static void removeGameObject(const int& index);

  static int getNumObjects();

  static Mesh* getMeshArray();
  static Collider* getColliderArray();

private:
  // component arrays are always sorted with active components first
  static Mesh meshes[MAX_GAMEOBJECTS];
  static Collider colliders[MAX_GAMEOBJECTS];

  static int currentNumObjects;
};
