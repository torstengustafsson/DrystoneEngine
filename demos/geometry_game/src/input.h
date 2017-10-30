#pragma once

#include "datastructures/Vector.h"
#include "input/inc/InputCommand.h"

class MoveCameraCommand : public InputCommand {
public:
  MoveCameraCommand(vector::Vec4 _direction, float _speed);
  void execute() override;
private:
  vector::Vec4 direction;
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
