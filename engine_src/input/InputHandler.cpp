#include "input/InputHandler.h"
#include "core/inc/Globals.h"
#include "core/inc/Log.h"

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

void InputHandler::handleInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {

    if (event.type == SDL_QUIT) {
      Globals::quit = true;
    }

    if(event.type == SDL_KEYDOWN) {
      int key = event.key.keysym.sym;

      if (inputMappings.find(key) != inputMappings.end()) {
        inputMappings[key]->execute();
      }
    }

  }
}
