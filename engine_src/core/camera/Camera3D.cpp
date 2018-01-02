
#include "core/camera/Camera3D.h"
#include "core/inc/Log.h"

#include <cmath>

Camera3D::Camera3D(float _fov, float _near, float _far, linalg::Vec2& _aspect)
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
  setPosition(position + pos);
}

void Camera3D::setPosition(linalg::Vec3 pos) {
  position = pos;
}

void Camera3D::rotX(float angle) {

}

void Camera3D::rotY(float angle) {

}

void Camera3D::rotZ(float angle) {

}

const linalg::Mat4 Camera3D::getView() const {
  linalg::Mat4 view;

  linalg::Mat4 posM = linalg::Mat4::MakeTranslation(position);
  linalg::Mat4 rotM = linalg::Mat4::MakeOrientation(orientation);
  return posM * rotM; // TODO: correct order?
}

const linalg::Mat4 Camera3D::getProjection() const {
  return projection;
}

void Camera3D::updateProjection() {
  float scaleNorm = fmax(aspect.x, aspect.y);
  float scaleX = aspect.x * (1 / (tan((fov / 2.0) + (linalg::PI / 180.0)))) / scaleNorm;
  float scaleY = aspect.y * (1 / (tan((fov / 2.0) + (linalg::PI / 180.0)))) / scaleNorm;
  float mapZ = -(far) / (far - near);
  float mapW = -(far * near) / (far - near);

  projection = linalg::Mat4(scaleX, 0,      0,    0,
                            0,      scaleY, 0,    0,
                            0,      0,      mapZ, mapW,
                            0,      0,     -1,    0);
}
