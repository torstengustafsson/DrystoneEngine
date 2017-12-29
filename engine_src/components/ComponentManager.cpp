#include "components/ComponentManager.h"
#include "world/GameObject.h"
#include "core/inc/Log.h"

Mesh ComponentManager::meshes[MAX_GAMEOBJECTS];
Collider ComponentManager::colliders[MAX_GAMEOBJECTS];
int ComponentManager::currentNumObjects = 0;

GameObject ComponentManager::addGameObject(const Mesh& mesh) {
  int index = currentNumObjects;
  currentNumObjects++;
  meshes[index] = Mesh(mesh);
  return GameObject(index, &meshes[index]);
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
    log_verbose("Error: Cannot remove game object (index higher than number of active instances)");
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
