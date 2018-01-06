#pragma once

#include "core/camera/CameraHandler.h"

/*
* Factory for creating specific cameras.
* Currently supports:
* FPS camera        - 3D movement using sphereical coordinates.
* Quaternion camera - 3D movement using quaternions. Use to avoid problems such as gimbal lock.
* 2D camera         - 2D movement in x- and y dimensions.
*/

enum class CameraType {
  CAM_FPS,
  CAM_QUAT,
  CAM_2D
};

class CameraFactory {
public:

  CameraHandler createFPSCamera(std::shared_ptr<InputHandler> inputHandler);
  CameraHandler createQuatCamera(std::shared_ptr<InputHandler> inputHandler);
  CameraHandler create2DCamera(std::shared_ptr<InputHandler> inputHandler);
};
