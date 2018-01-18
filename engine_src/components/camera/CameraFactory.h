#pragma once

#include "components/camera/Camera.h"

/*
* Factory for creating specific cameras.
* Currently supports:
* FPS camera        - 3D movement using sphereical coordinates.
* Quaternion camera - 3D movement using quaternions. Use to avoid problems such as gimbal lock.
* 2D camera         - 2D movement in x- and y dimensions.
*/

class CameraFactory {
public:
  static std::shared_ptr<Camera> createFPSCamera(std::shared_ptr<InputHandler> inputHandler);
  static std::shared_ptr<Camera> createQuatCamera(std::shared_ptr<InputHandler> inputHandler);
  static std::shared_ptr<Camera> create2DCamera(std::shared_ptr<InputHandler> inputHandler);
};
