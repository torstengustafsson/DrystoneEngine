#include "components/EventHandler.h"

void EventHandler::setInputHandler(InputHandler& _inputHandler) {
  inputHandler = _inputHandler;
}

void EventHandler::addInputMapping(const int key, std::shared_ptr<InputCommand> command) {
  inputHandler.addInputMapping(key, command);
}
