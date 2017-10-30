#include "world/GameObject.h"

GameObject::GameObject(std::shared_ptr<Mesh> _mesh)
  : mesh(_mesh) {
}

void GameObject::render() {
  if (mesh) {
    mesh->render();
  }
}

int GameObject::getCameraX() {
  return xPosCamera;
}
int GameObject::getCameraY() {
  return yPosCamera;
}
int GameObject::getWorldX() {
  return xPosWorld;
}
int GameObject::getWorldY() {
  return yPosWorld;
}
