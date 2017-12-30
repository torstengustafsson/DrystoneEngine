#include "components/EventHandler.h"
#include "input/InputHandler.h"

void EventHandler::setInputHandler(std::shared_ptr<InputHandler> _inputHandler) {
  inputHandler = _inputHandler;
}

void EventHandler::addInputMapping(const int key, std::shared_ptr<InputCommand> command) {
  inputHandler->addInputMapping(key, command);
}
