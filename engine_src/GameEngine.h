#pragma once

#include "core/GameRenderer.h"
#include "core/GameController.h"
#include "components/camera/Camera.h"
#include "input/InputHandler.h"

#include <memory>
#include <chrono>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

/*
* TODO: write description
*/

// forward declarations
class GameObject;

class GameEngine {
public:
  GameEngine(std::shared_ptr<InputHandler> inputHandler, const int fps = 60);
  GameEngine(const int fps = 60);

  void frame();
  void run();

  std::shared_ptr<InputHandler> inputHandler();
  
  void addGameObject(const GameObject& objectPrototype);
  
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

  // game renderer controls SDL window and renderer
  std::shared_ptr<Camera> gameCamera; // TODO: camera should be component of gameobject instead

  // game controller handles game logic.
  std::unique_ptr<GameController> gameController;

  // game renderer controls SDL window and renderer
  std::unique_ptr<GameRenderer> gameRenderer;
};
