#pragma once

#include <string>

/*
* Contains the necessary global state of the game.
* Initialized in GameEngine.cpp
*/

struct Globals {
  static bool quit;
  static const std::string PATH;
};
