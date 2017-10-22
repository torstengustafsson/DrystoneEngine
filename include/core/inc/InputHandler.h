#pragma once

#include <memory>
#include "SDL.h"
#include "world/inc/Player.h"

/*
* TODO: write description
*/

class InputHandler {
public:
  InputHandler(std::shared_ptr<Player> _player);

  InputHandler & operator=(const InputHandler&) = delete;
  InputHandler(const InputHandler&) = delete;

  void handleInput();

private:
  std::shared_ptr<Player> player;
};
