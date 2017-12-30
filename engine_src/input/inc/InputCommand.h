#pragma once

#include "SDL.h" // for SDL input mappings

/*
* Interface for input commands. implementations of 
* this is used by the input handler.
*/

class InputCommand {
public:
  virtual void execute() = 0;
};
