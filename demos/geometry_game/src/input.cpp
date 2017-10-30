#include "input.h"
#include "input/inc/InputCommand.h"

MoveCameraCommand::MoveCameraCommand(vector::Vec4 _direction, float _speed)
  : direction(_direction),
    speed(_speed) {
}

void MoveCameraCommand::execute() {

}

ZoomCameraCommand::ZoomCameraCommand(bool _zoomIn, float _speed)
  : zoomIn(_zoomIn),
    speed(_speed) {
}

void ZoomCameraCommand::execute() {

}
