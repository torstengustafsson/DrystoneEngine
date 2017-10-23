#include <chrono>
#include "core/inc/Globals.h"
#include "core/inc/Game.h"

// initialize global variables
// defined in "core/inc/Globals.h"
namespace Globals {
  bool quit = false;
}

int main(int argc, char *argv[]) {

  Game theGame;

  const int SCREEN_TICKS_PER_FRAME = 1000 / 60;

  //The frames per second cap timer
  std::chrono::high_resolution_clock::time_point timer;

  while (!Globals::quit) {
    timer = std::chrono::high_resolution_clock::now();

    // run the game
    theGame.frame();

    // lock framerate
    std::chrono::nanoseconds elapsed = std::chrono::high_resolution_clock::now() - timer;
    int frameTicks = elapsed.count(); // if frame finished early
    if (frameTicks < SCREEN_TICKS_PER_FRAME) {
      SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks); // wait remaining time
    }
  }

  return 0;
}
