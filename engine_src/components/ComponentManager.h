#pragma once 

#include "components/Mesh.h"

/*
* Singleton class.
* 
* Manages all GameObject components. The actual objects are stored here, and each GameObject 
* holds references to its individual components.
* This allows for better performance in the game loop, as it can loop through arrays of data, 
* instead of looping through pointers to data.
*/

#define MAX_GAMEOBJECTS 1000

class ComponentManager {
public:

  static void addGameObject(Mesh& mesh);

  static Mesh* getMeshArray();

private:
  static Mesh meshes[MAX_GAMEOBJECTS];
};
