
#include "input/InputHandler.h"
#include "components/camera/CameraHandler.h"
#include "components/camera/Camera.h"
#include "core/inc/Log.h"

CameraHandler::CameraHandler(std::shared_ptr<Camera> _camera, std::shared_ptr<InputHandler> _inputHandler) 
  : camera(_camera),
    inputHandler(_inputHandler) {
}

void CameraHandler::setKeyBinding(const CameraInput& camInput, const int& key) {
  commands.push_back(std::make_shared<CameraCommand>(camera, camInput));
  inputHandler->addInputMapping(key, commands.back());
}

void CameraHandler::setKeyBinding(const CameraInput& camInput, const std::initializer_list<int> keys) {
	for (auto it = keys.begin(); it != keys.end(); ++it) {
		setKeyBinding(camInput, *it);
	}
}
