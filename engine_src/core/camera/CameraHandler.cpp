
#include "core/camera/CameraHandler.h"
#include "core/inc/Log.h"

CameraHandler::CameraHandler(std::shared_ptr<InputHandler> _inputHandler) {
  inputHandler = _inputHandler;
}

void CameraHandler::setKeyBinding(const CameraInput& camInput, const int& key) {
  //inputHandler->addInputMapping(key, <add input commands>);
}

void CameraHandler::setKeyBinding(const CameraInput& camInput, const std::initializer_list<int>& keys) {

}
