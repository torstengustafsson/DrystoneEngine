#include "core/inc/Globals.h"
#include "core/Game.h"

#include <iostream>

int main(int argc, char *argv[]) {

  int fps = 60;
  if (argc > 1) {
    fps = std::stoi(argv[1]);
  }

  Game theGame(fps);

  while (!Globals::quit) {
    // run the game
    theGame.frame();
  }

  return 0;
}
