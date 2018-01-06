#pragma once

#include "input/InputHandler.h"
#include <memory>
#include <initializer_list>

/*
* Handler for the game cameras input. Controls the cameras 
* transformations, such as rotation and movement.
*/

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

class CameraHandler {
public:
  CameraHandler(std::shared_ptr<InputHandler> _inputHandler);

  void setKeyBinding(const CameraInput& camInput, const int& key);
  void setKeyBinding(const CameraInput& camInput, const std::initializer_list<int>& keys);

private:
  std::shared_ptr<InputHandler> inputHandler;
};
