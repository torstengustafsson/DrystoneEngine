#include "world/GameObject.h"
#include "linalg/Vec3.h"
#include "components/Mesh.h"
#include "components/ComponentManager.h"

GameObject::GameObject(const int& _index, Mesh* _mesh)
  : index(_index),
    mesh(_mesh) {
}

GameObject::~GameObject() {
  ComponentManager::removeGameObject(index);
}

void GameObject::setTranslation(const linalg::Vec3& pos) {
  transform->setTranslation(pos);
}

void GameObject::translate(const linalg::Vec3& vec) {
  setTranslation(getPosition() + vec);
}

linalg::Vec3 GameObject::getPosition() const {
  return transform->getTranslation();
}

const Mesh* GameObject::getMesh() const {
  return mesh;
}

void GameObject::addChild(const GameObject& child) {
  // TODO
  //children.push_back(child);
}
