
#include "core/camera/Camera3D.h"
#include <cmath>

Camera3D::Camera3D(float _fov, float _near, float _far, linalg::Vec2 _aspect)
  : fov(_fov),
    near(_near),
    far(_far),
    aspect(_aspect) {

  updateProjection();
}

Camera3D::Camera3D(float _fov, float _near, float _far, int aspectX, int aspectY)
  : Camera3D(_fov, _near, _far, linalg::Vec2(aspectX, aspectY)) {
}

void Camera3D::translate(linalg::Vec3 pos) {
  setTranslation(transform.getTranslation() + pos);
}

void Camera3D::setTranslation(linalg::Vec3 pos) {
  transform.setTranslation(pos);
}

void Camera3D::rotX(float angle) {

}

void Camera3D::rotY(float angle) {

}

void Camera3D::rotZ(float angle) {

}

const linalg::Mat4& Camera3D::getView() const {
  return transform;
}

const linalg::Mat4& Camera3D::getProjection() const {
  return projection;
}

void Camera3D::updateProjection() {
  float scaleX = aspect.x * (1 / (tan((fov / 2.0) + (PI / 180.0))));
  float scaleY = aspect.y * (1 / (tan((fov / 2.0) + (PI / 180.0))));
  float mapZ = -(far) / (far - near);
  float mapW = -(far * near) / (far - near);

  projection = linalg::Mat4(scaleX, 0, 0, 0,
    0, scaleY, 0, 0,
    0, 0, mapZ, -1,
    0, 0, mapW, 0);
}
