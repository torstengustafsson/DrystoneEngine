
#include "components/camera/CameraFactory.h"
#include "core/inc/Log.h"

std::shared_ptr<Camera> CameraFactory::createFPSCamera(std::shared_ptr<InputHandler> inputHandler) {
  auto camera = std::make_shared<Camera>(CameraType::CAM_FPS, ProjectionType::PERSPECTIVE);
  CameraHandler handler(camera, inputHandler);
  handler.setKeyBinding(CameraInput::MOVE_FORWARD, {SDLK_w, SDLK_UP});
  handler.setKeyBinding(CameraInput::MOVE_BACKWARD, { SDLK_s, SDLK_DOWN });
  handler.setKeyBinding(CameraInput::MOVE_LEFT, { SDLK_a, SDLK_LEFT });
  handler.setKeyBinding(CameraInput::MOVE_RIGHT, { SDLK_d, SDLK_RIGHT });
  return camera;
}

std::shared_ptr<Camera> CameraFactory::createQuatCamera(std::shared_ptr<InputHandler> inputHandler) {
	auto camera = std::make_shared<Camera>(CameraType::CAM_QUAT, ProjectionType::PERSPECTIVE);
	return camera;
}

std::shared_ptr<Camera> CameraFactory::create2DCamera(std::shared_ptr<InputHandler> inputHandler) {
	auto camera = std::make_shared<Camera>(CameraType::CAM_2D, ProjectionType::PERSPECTIVE);
	return camera;
}
