#include "world/GameObject.h"
#include "linalg/Vec3.h"
#include "components/Mesh.h"

GameObject::GameObject(std::shared_ptr<Mesh> _mesh)
  : mesh(_mesh) {
}

void GameObject::render(const linalg::Mat4& frameOfReference, const linalg::Mat4& View, const linalg::Mat4& Projection) {
  linalg::Mat4 adjTransform = frameOfReference * transform;
  if (mesh) {
    mesh->render(adjTransform, View, Projection);
  }

  for (auto child : children) {
    //child.render(adjTransform, View, Projection);
  }
}

void GameObject::setTranslation(const linalg::Vec3& pos) {
  transform.setTranslation(pos);
}

void GameObject::translate(const linalg::Vec3& vec) {
  setTranslation(getPosition() + vec);
}

linalg::Vec3 GameObject::getPosition() const {
  return transform.getTranslation();
}

std::shared_ptr<Mesh> GameObject::getMesh() const {
  return mesh;
}

//std::vector<GameObject> GameObject::getChildren() {
//  return children;
//}

//void GameObject::addChild(std::shared_ptr<GameObject> child) {
//  children.push_back(*child);
//}

void GameObject::addChild(const GameObject& child) {
  children.push_back(child);
}

//void GameObject::removeChild(const std::shared_ptr<GameObject>& child) {
//  // TODO
//}
//
//void GameObject::removeChild(const GameObject& child) {
//  // TODO
//}
