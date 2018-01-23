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
  GameEngine(InputHandler& _inputHandler, const int fps = 60);
  GameEngine(const int fps = 60);

  void frame();
  void run();

  InputHandler& getInputHandler();
  
  void addGameObject(const GameObject& objectPrototype);
  
  void addCamera(CameraType type, bool mouseLock, bool active);

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
  InputHandler inputHandler;

  // game controller handles game logic.
  GameController gameController;

  // game renderer controls SDL window and renderer
  GameRenderer gameRenderer;
};
