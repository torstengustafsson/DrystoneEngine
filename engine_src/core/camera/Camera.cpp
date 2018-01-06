
#include "core/camera/Camera.h"
#include "core/inc/Log.h"

#include <cmath>

Camera::Camera(CameraType camType, ProjectionType projType) {
  updateProjection(linalg::PI / 3.0, 0.1, 10000.0, 800, 600);
}

void Camera::translate(linalg::Vec3 pos) {
  setPosition(position + pos);
}

void Camera::setPosition(linalg::Vec3 pos) {
  position = pos;
}

void Camera::rotX(float angle) {

}

void Camera::rotY(float angle) {

}

void Camera::rotZ(float angle) {

}

const linalg::Mat4 Camera::getView() const {
  linalg::Mat4 view;

  linalg::Mat4 posM = linalg::Mat4::MakeTranslation(position);
  linalg::Mat4 rotM = linalg::Mat4::MakeOrientation(orientation);
  return posM * rotM; // TODO: correct order?
}

const linalg::Mat4 Camera::getProjection() const {
  return projection;
}

void Camera::updateProjection(float fov, float near, float far, int aspectX, int aspectY) {
  float scaleNorm = fmax(aspectX, aspectY);
  float scaleX = aspectX * (1 / (tan((fov / 2.0) + (linalg::PI / 180.0)))) / scaleNorm;
  float scaleY = aspectY * (1 / (tan((fov / 2.0) + (linalg::PI / 180.0)))) / scaleNorm;
  float mapZ = -(far) / (far - near);
  float mapW = -(far * near) / (far - near);

  // TODO: improve projection matrix to handle depth better
  // http://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/opengl-perspective-projection-matrix
  projection = linalg::Mat4(scaleX, 0,      0,    0,
                            0,      scaleY, 0,    0,
                            0,      0,      mapZ, mapW,
                            0,      0,     -1,    0);
}
