#pragma once

#include "input/inc/InputCommand.h"
#include <functional>
#include <memory>

enum class CameraInput {
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_UP,
  MOVE_DOWN,
  MOVE_FORWARD,
  MOVE_BACKWARD,
  ZOOM_IN,
  ZOOM_OUT
};

/*
* Represents the actual camera commands, such as moving forward or rotating.
*/

// forward declarations
class Camera;

class CameraCommand : public InputCommand {
public:
	CameraCommand(std::shared_ptr<Camera> _camera, const CameraInput commandType);
	void execute() override;

private:
  std::shared_ptr<Camera> camera;
	std::function<void(std::shared_ptr<Camera>)> command;
};

