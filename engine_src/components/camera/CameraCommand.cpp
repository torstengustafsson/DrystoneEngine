
#include "components/camera/CameraCommand.h"
#include "components/camera/Camera.h"
#include "linalg/Vec3.h"
#include "core/inc/Log.h"

CameraCommand::CameraCommand(std::shared_ptr<Camera> _camera, const CameraInput commandType)
  : camera(_camera) {

	switch (commandType) {
  case CameraInput::MOVE_FORWARD:
    command = [](std::shared_ptr<Camera> _camera){
      _camera->translate(linalg::Vec3(0.0f, 0.0f, 0.1f));
    };
    break;
  case CameraInput::MOVE_BACKWARD:
    command = [](std::shared_ptr<Camera> _camera) {
      _camera->translate(linalg::Vec3(0.0f, 0.0f, -0.1f));
    };
    break;
  case CameraInput::MOVE_LEFT:
    command = [](std::shared_ptr<Camera> _camera) {
      _camera->translate(linalg::Vec3(0.1f, 0.0f, 0.0f));
    };
    break;
  case CameraInput::MOVE_RIGHT:
    command = [](std::shared_ptr<Camera> _camera) {
      _camera->translate(linalg::Vec3(-0.1f, 0.0f, 0.0f));
    };
    break;
	default:
    log_verbose("Error: Trying to create camera command that doesn't exist!");
	}

}

void CameraCommand::execute() {
  command(camera);
}
