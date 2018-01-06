
#include "core/camera/CameraFactory.h"
#include "core/inc/Log.h"

CameraHandler CameraFactory::createFPSCamera(std::shared_ptr<InputHandler> inputHandler) {
  CameraHandler handler(inputHandler);
  handler.setKeyBinding(CameraInput::MOVE_FORWARD, {SDLK_w, SDLK_UP});
  return handler;
}

CameraHandler CameraFactory::createQuatCamera(std::shared_ptr<InputHandler> inputHandler) {
  CameraHandler handler(inputHandler);

  // TODO

  return handler;
}

CameraHandler CameraFactory::create2DCamera(std::shared_ptr<InputHandler> inputHandler) {
  CameraHandler handler(inputHandler);

  // TODO

  return handler;
}
