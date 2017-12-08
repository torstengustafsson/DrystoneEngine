#include "world/GameObject.h"

GameObject::GameObject(std::shared_ptr<Mesh> _mesh)
  : mesh(_mesh) {
}

void GameObject::render(const linalg::Mat4& V, const linalg::Mat4& P) {
  if (mesh) {
    mesh->render(transform, V, P);
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
