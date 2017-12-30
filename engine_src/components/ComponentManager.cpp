#include "components/ComponentManager.h"
#include "world/GameObject.h"
#include "core/inc/Log.h"

Mesh ComponentManager::meshes[MAX_GAMEOBJECTS];
Collider ComponentManager::colliders[MAX_GAMEOBJECTS];
int ComponentManager::currentNumObjects = 0;

GameObject ComponentManager::addGameObject(const GameObject& objectPrototype) {
  int index = currentNumObjects;
  currentNumObjects++;
  meshes[index] = Mesh(*(objectPrototype.getMesh())); // recreate the mesh and store in mesh array
  
  // create and return the game object to be used by the game engine
  GameObject* gameObject = new GameObject(index, &meshes[index]);  
  for (auto e : objectPrototype.getEventHandlers()) {
    gameObject->addEventHandler(e);
  }
  return *gameObject;
}

void ComponentManager::removeGameObject(const int& index) {
  if (index < currentNumObjects) {
    // move remaining components back to keep arrays sorted
    for (int i = index; i < currentNumObjects - 1; i++) {
      meshes[i] = meshes[i+1];
    }
    currentNumObjects--;
  }
  else {
    log_verbose("Error: Cannot remove game object with index " + std::to_string(index) + " (index higher than number of active instances)");
  }
}

int ComponentManager::getNumObjects() {
  return currentNumObjects;
}

Mesh* ComponentManager::getMeshArray() {
  return meshes;
}

Collider* ComponentManager::getColliderArray() {
  return colliders;
}
