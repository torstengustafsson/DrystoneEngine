#pragma once

#include "linalg/Vector.h"
#include "input/inc/InputCommand.h"

class MoveCameraCommand : public InputCommand {
public:
  MoveCameraCommand(linalg::Vec4 _direction, float _speed);
  void execute() override;
private:
  linalg::Vec4 direction;
  int speed;
};

class ZoomCameraCommand: public InputCommand {
public:
  ZoomCameraCommand(bool _zoomIn, float speed);
  void execute() override;
private:
  bool zoomIn;
  float speed;
};
