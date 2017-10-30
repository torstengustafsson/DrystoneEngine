#pragma once

#include <memory>
#include <chrono>
#include "core/inc/Globals.h"
#include "core/GameRenderer.h"
#include "core/GameController.h"
#include "input/InputHandler.h"
#include "world/GameObject.h"

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

/*
* TODO: write description
*/

class GameEngine {
public:
  GameEngine(std::shared_ptr<InputHandler> inputHandler = nullptr, const int fps = 60);
  GameEngine(const int fps = 60);

  void frame();
  void run();

  std::shared_ptr<InputHandler> inputHandler();
  
  void addGameObject(std::shared_ptr<GameObject> o);
  
private:

  void handleInput();
  void update();
  void render();
  void delayFramerate();

#ifdef EMSCRIPTEN
  void main_loop();
#endif

  // handles locking of framerate
  std::chrono::high_resolution_clock::time_point timer;
  const int FPS;

  // input handler handles user input such as key and mouse presses
  std::shared_ptr<InputHandler> inputHandler_;

  // game controller handles game logic.
  std::unique_ptr<GameController> gameController_;

  // game renderer controls SDL window and renderer
  std::unique_ptr<GameRenderer> gameRenderer_;

};