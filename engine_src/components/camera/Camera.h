#pragma once

#include "components/camera/CameraHandler.h"
#include "linalg/linalg.h"
#include "core/util/UuidGenerator.h"
#include <memory>

/*
* Camera for 3D movement. Default initializes its input mapping 
* to use the arrow keys. The input mapping may be rebound.
* Note: All camera types will automatically bind WASD and arrow keys.
*       as well as mouse motion handling.
*       These can be unbound/rebound if necessary.
*/

// forward declarations
class GameRenderer;

enum class ProjectionType {
  PERSPECTIVE,
  ORTHOGRAPHIC,
};

enum class CameraType {
	CAM_FPS,
	CAM_QUAT,
	CAM_2D
};

class Camera {
public:
  Camera(CameraType camType, ProjectionType projType);

  void updateProjection(float fov, float near, float far, int aspectX, int aspectY);

  void translate(linalg::Vec3 pos);
  void setPosition(linalg::Vec3 pos);
  void rotX(float angle);
  void rotY(float angle);
  void rotZ(float angle);

  const linalg::Mat4 getView() const;
  const linalg::Mat4 getProjection() const;

  // TODO: handle camera shakes using this method
  // void shake(float magnitude, float time, float fadeTime);

  bool operator==(const Camera& rhs);

private:
  util::Uuid id = util::UuidGenerator::newUUID();

  linalg::Mat4 projection;

  // TODO: handle camera shakes using this matrix
  // linalg::Mat4 cameraShake;

  linalg::Vec3 position;
  linalg::Quat orientation;
};
