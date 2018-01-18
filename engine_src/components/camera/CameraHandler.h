#pragma once

#include "components/camera/CameraCommand.h"
#include <memory>
#include <vector>
#include <initializer_list>

/*
* Handler for the game cameras input. Controls the cameras 
* transformations, such as rotation and movement.
*/

// forward declarations
class InputHandler;
class Camera;

class CameraHandler {
public:
  CameraHandler(std::shared_ptr<Camera> _Camera, std::shared_ptr<InputHandler> _inputHandler);

  void setKeyBinding(const CameraInput& camInput, const int& key);
  void setKeyBinding(const CameraInput& camInput, const std::initializer_list<int> keys);

private:
  std::vector<std::shared_ptr<CameraCommand>> commands;
  std::shared_ptr<Camera> camera;
  std::shared_ptr<InputHandler> inputHandler;
};

