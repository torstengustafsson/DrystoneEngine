#pragma once

#include <memory>
#include "GameRenderer.h"
#include "GameController.h"
#include "GameEngine.h"
#include "world/inc/GameObject.h"
#include "world/inc/Player.h"
#include "world/inc/Camera.h"

/*
* TODO: write description
*/

class Game {
public:
  Game();

  void frame();

private:
  // game renderer class controls SDL window and renderer
  std::unique_ptr<GameRenderer> gameRenderer;

  // game controller handles game logic.
  std::unique_ptr<GameController> gameController;

  // game engine handles collisions and movement of objects
  std::unique_ptr<GameEngine> gameEngine;

  // the player object is passed around to handler classes so pointer type is recommended
  std::shared_ptr<Player> player;

  // camera class handles viewport (centers player on screen)
  std::unique_ptr<Camera> camera;

  SDL_Event e;
};