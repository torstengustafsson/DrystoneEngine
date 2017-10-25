#include "core/inc/Globals.h"
#include "core/inc/Game.h"

// initialize global variables
// defined in "core/inc/Globals.h"
namespace Globals {
  bool quit = false;
}

int main(/*int argc, char *argv[]*/) {

  Game theGame;

  while (!Globals::quit) {
    // run the game
    theGame.frame();
  }

  return 0;
}
