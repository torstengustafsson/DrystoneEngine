#include "input/InputHandler.h"
#include "core/inc/Globals.h"
#include "core/inc/Log.h"
#include "SDL_events.h"

// default constructor initializes basic input commands
InputHandler::InputHandler() {
  log("Input Handler Created!");
}

void InputHandler::addInputMapping(const int key, std::shared_ptr<InputCommand> command) {
  inputMappings[key] = std::shared_ptr<InputCommand>(command);
}

void InputHandler::addInputMapping(const int key, InputCommand* command) {
  std::shared_ptr<InputCommand> cmd(command);
  addInputMapping(key, cmd);
}

void InputHandler::removeInputMapping(const int key) {
  inputMappings[key].reset();
}

void InputHandler::setMouseMotionEvent(std::shared_ptr<MouseMotionEvent> _mouseEvent) {
  mouseMotionEvent = _mouseEvent;
}

void InputHandler::handleInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {

    switch (event.type) {
    case SDL_QUIT:
      Globals::quit = true;
      break;
    case SDL_KEYDOWN: {
      int key = event.key.keysym.sym;

      if (inputMappings.find(key) != inputMappings.end()) {
        inputMappings[key]->execute();
      }
      break;
    }
    case SDL_MOUSEMOTION:
      if (mouseMotionEvent != nullptr) {
        mouseMotionEvent->execute(event.motion.x, event.motion.y);
      }
    case SDL_MOUSEBUTTONDOWN:
      if (mouseClickEvent != nullptr) {
        mouseClickEvent->execute(event.button.button, event.motion.x, event.motion.y);
      }
    default:
      break;
    }
  }
}
