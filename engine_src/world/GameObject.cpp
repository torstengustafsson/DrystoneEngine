#include "world/GameObject.h"
#include "linalg/Vec3.h"
#include "components/Mesh.h"
#include "components/ComponentManager.h"
#include "components/EventHandler.h"
#include "core/inc/Log.h"

GameObject::GameObject(const int& _index, Mesh* _mesh)
  : index(_index),
    mesh(_mesh) {
}

GameObject::~GameObject() {
  if (index == GO_PROTOTYPE) {
    delete mesh;
  }

  for (auto e : eventHandlers) {
    e->destroy();
  }
}

Mesh* GameObject::getMesh() const {
  return mesh;
}

void GameObject::setPosition(const linalg::Vec3& pos) {
  mesh->setPosition(pos);
}

void GameObject::addEventHandler(std::shared_ptr<EventHandler> eventHandler) {
  eventHandler->gameObject = std::make_shared<GameObject>(*this);
  eventHandler->init();
  eventHandlers.push_back(eventHandler);
}

const int GameObject::getIndex() const {
  return index;
}

const std::vector<std::shared_ptr<EventHandler>>& GameObject::getEventHandlers() const {
  return eventHandlers;
}

void GameObject::runEventHandlers() {
  for (auto e : eventHandlers) {
     e->update();
  }
}

//void GameObject::addChild(const GameObject& child) {
  // TODO
  //children.push_back(child);
//}

bool GameObject::operator==(const GameObject& rhs) {
  return index == rhs.getIndex();
}

GameObject& GameObject::operator=(const GameObject& rhs) {
  return GameObject(rhs);
}
