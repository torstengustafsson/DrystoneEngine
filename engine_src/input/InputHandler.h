#pragma once

#include <map>
#include <memory>
#include "SDL.h"
#include "input/inc/InputConstants.h"
#include "input/InputCommands.h"

/*
* TODO: write description
*/

class InputHandler {
public:
  InputHandler();

  InputHandler & operator=(const InputHandler&) = delete;
  InputHandler(const InputHandler&) = delete;

  void handleInput();

private:
  std::map<int, int> rawInputMappings; // conversions between SDL input mapping and game input mapping
  std::map<int, std::shared_ptr<InputCommand>> inputMappings; // game input mappings to the actual commands

  void initRawInputMappings();
  void initInputMappings();
};
