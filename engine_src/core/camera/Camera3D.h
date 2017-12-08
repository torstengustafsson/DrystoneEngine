#pragma once

#include <linalg/linalg.h>

/*
* TODO: write description
*/

class Camera3D {
public:
  Camera3D(float _fov, float _near, float _far, linalg::Vec2 _aspect);
  Camera3D(float _fov, float _near, float _far, int aspectX, int aspectY);

  void translate(linalg::Vec3 pos);
  void setTranslation(linalg::Vec3 pos);
  void rotX(float angle);
  void rotY(float angle);
  void rotZ(float angle);

  const linalg::Mat4& getView() const;
  const linalg::Mat4& getProjection() const;

private:

  void updateProjection();

  float fov;
  float near;
  float far;
  linalg::Vec2 aspect;

  linalg::Mat4 projection;
  linalg::Mat4 view;
};
