#include "input/inc/InputHandler.h"
#include "core/inc/Globals.h"

InputHandler::InputHandler() {
  
  initRawInputMappings();
  initInputMappings();
}

// map raw input to the input types used by the game
void InputHandler::initRawInputMappings() {
  rawInputMappings[SDLK_r] = KEYS::SET_COLOR_RED;
  rawInputMappings[SDLK_g] = KEYS::SET_COLOR_GREEN;
  rawInputMappings[SDLK_b] = KEYS::SET_COLOR_BLUE;
}

// map input to commands
void InputHandler::initInputMappings() {
  inputMappings[KEYS::SET_COLOR_RED] = std::unique_ptr<InputCommand>(new ChangeBGColorCommand(vector::Vec4(1, 0, 0, 1)));
  inputMappings[KEYS::SET_COLOR_GREEN] = std::unique_ptr<InputCommand>(new ChangeBGColorCommand(vector::Vec4(0, 1, 0, 1)));
  inputMappings[KEYS::SET_COLOR_BLUE] = std::unique_ptr<InputCommand>(new ChangeBGColorCommand(vector::Vec4(0, 0, 1, 1)));
}

void InputHandler::handleInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {

    if (event.type == SDL_QUIT) {
      globals::quit = true;
    }

    if(event.type == SDL_KEYDOWN) {
      int key = event.key.keysym.sym;

      if (rawInputMappings.find(key) != rawInputMappings.end()) {
        inputMappings[rawInputMappings[key]]->execute();
      }
    }

  }
}
