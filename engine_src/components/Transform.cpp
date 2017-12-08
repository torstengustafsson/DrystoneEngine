#include "components/Transform.h"

Transform::Transform() {
}

Transform::Transform(linalg::Vec3 pos, linalg::Quat orientation) {
  transform.setTranslation(pos);
}

void Transform::setTranslation(const linalg::Vec3& pos) {
  transform.setTranslation(pos);
}

void Transform::setScale(const linalg::Vec3& scale) {
  transform.setScale(scale);
}

void Transform::setOrientation(const linalg::Quat orientation) {
  transform.setOrientation(orientation);
}

linalg::Vec3 Transform::getTranslation() const {
  return transform.getTranslation();
}

linalg::Vec3 Transform::getScale() const {
  return transform.getScale();
}
