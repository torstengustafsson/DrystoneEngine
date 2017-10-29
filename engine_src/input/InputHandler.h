#pragma once

#include <map>
#include <memory>
#include <vector>
#include "SDL.h"
#include "input/inc/InputCommand.h"

/*
* Each game uses an input handler to handle user input.
* Input can be mapped and remapped to commands dynamically 
* in runtime.
*/

class InputHandler {
public:
  InputHandler();

  InputHandler & operator=(const InputHandler&) = delete;
  InputHandler(const InputHandler&) = delete;

  void addInputMapping(const int key, std::shared_ptr<InputCommand> command);
  void addInputMapping(const int key, InputCommand* command);
  void removeInputMapping(const int key);

  // this would be nice to have, but is difficult because 
  // InputCommand is an interface (abstract class), and this is C++
  //void addInputMapping(const int key, InputCommand& command);

  void handleInput();

private:
  std::map<int, std::shared_ptr<InputCommand>> inputMappings; // game input mappings to the actual commands
};
