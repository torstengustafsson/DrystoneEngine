#pragma once

#include "SDL_keycode.h"

/*
* Interface for input commands. implementations of 
* this is used by the input handler.
*/

class InputCommand {
public:
  virtual void execute() = 0;
};

class MouseMotionEvent {
public:
  virtual void execute(const int mouseX, const int mouseY) = 0;
};

class MouseClickEvent {
public:
  virtual void execute(const int button, const int mouseX, const int mouseY) = 0;
};
