#pragma once

#include <memory>
#include <chrono>
#include "core/inc/Globals.h"
#include "GameRenderer.h"
#include "GameController.h"
#include "GameEngine.h"
#include "input/InputHandler.h"
#include "world/GameObject.h"

/*
* TODO: write description
*/

class Game {
public:
  Game(std::shared_ptr<InputHandler> inputHandler = nullptr, const int fps = 60);
  Game(InputHandler& inputHandler, const int fps = 60);

  void frame();

  std::shared_ptr<InputHandler> inputHandler();

private:

  void handleInput();
  void update();
  void render();
  void delayFramerate();

  // handles locking of framerate
  std::chrono::high_resolution_clock::time_point timer;
  const int FPS;

  // input handler handles user input such as key and mouse presses
  std::shared_ptr<InputHandler> inputHandler_;

  // game controller handles game logic.
  std::unique_ptr<GameController> gameController_;

  // game engine handles collisions and movement of objects
  std::unique_ptr<GameEngine> gameEngine_;

  // game renderer controls SDL window and renderer
  std::unique_ptr<GameRenderer> gameRenderer_;

};