#include "core/inc/Globals.h"
#include "core/inc/Game.h"

#include <iostream>

// initialize global variables
// defined in "core/inc/Globals.h"
namespace globals {
  bool quit = false;
}

int main(int argc, char *argv[]) {

  int fps = 60;
  if (argc > 1) {
    fps = std::stoi(argv[1]);
  }

  Game theGame(fps);

  while (!globals::quit) {
    // run the game
    theGame.frame();
  }

  return 0;
}
