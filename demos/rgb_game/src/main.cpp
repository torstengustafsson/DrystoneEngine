#include "core/Game.h"
#include "input.h"

#include <iostream>
#include <memory>

#ifdef EMSCRIPTEN
#include <emscripten.h>
Game theGame;
void main_loop() {
    theGame.frame();
}
#endif

int main(int argc, char *argv[]) {
#ifdef EMSCRIPTEN
  emscripten_set_main_loop(main_loop, 60, 1);
#else
  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 60;

  InputHandler inputHandler;
  inputHandler.addInputMapping(SDLK_r, ChangeBGColorCommand(vector::Vec4(1, 0, 0, 1)));
  inputHandler.addInputMapping(SDLK_g, ChangeBGColorCommand(vector::Vec4(0, 1, 0, 1)));
  inputHandler.addInputMapping(SDLK_b, ChangeBGColorCommand(vector::Vec4(0, 0, 1, 1)));

  Game theGame(inputHandler, fps);

  while (!Globals::quit) {
    // run the game
    theGame.frame();
  }
#endif

  return 0;
}
