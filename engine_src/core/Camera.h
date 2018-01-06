#pragma once

#include <linalg/linalg.h>

/*
* Camera for 3D movement. Default initializes its input mapping 
* to use the arrow keys. The input mapping may be rebound.
*/

class Camera {
public:

  enum class Projection {
    PERSPECTIVE,
    ORTHOGRAPHIC,
  };

  enum class Type {
    PERSPECTIVE,
    ORTHOGRAPHIC,
  };

  Camera(float _fov, float _near, float _far, linalg::Vec2& _aspect);
  Camera(float _fov, float _near, float _far, int aspectX, int aspectY);

  void translate(linalg::Vec3 pos);
  void setPosition(linalg::Vec3 pos);
  void rotX(float angle);
  void rotY(float angle);
  void rotZ(float angle);

  const linalg::Mat4 getView() const;
  const linalg::Mat4 getProjection() const;

private:

  void updateProjection();

  float fov;
  float near;
  float far;
  linalg::Vec2 aspect;

  linalg::Mat4 projection;

  linalg::Vec3 position;
  linalg::Quat orientation;

};
