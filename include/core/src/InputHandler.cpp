#include "core/inc/InputHandler.h"

InputHandler::InputHandler(std::shared_ptr<Player> _player) 
  : player(_player) {
}

void InputHandler::handleInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      // Exit game
    }

    if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        // Exit game
        break;
      case SDLK_r:
        // Cover with red and update
        break;
      case SDLK_g:
        // Cover with green and update
        break;
      case SDLK_b:
        // Cover with blue and update
        break;
      default:
        break;
      }
    }
  }
}
