#include "GameEngine.h"
#include "world/GameObjectFactory.h"
#include "core/inc/Log.h"
#include "input.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  const float MOVE_SPEED = 0.1f;

  GameObject Plane = GameObjectFactory::createPlane(0.5, 0.5);

  // add input
  std::shared_ptr<InputHandler> inputHandler = std::make_shared<InputHandler>();
  //inputHandler->addInputMapping(SDLK_LEFT,  new MoveObjectCommand(Plane, linalg::Vec3(-1,  0, 0), MOVE_SPEED)); // move camera left
  //inputHandler->addInputMapping(SDLK_RIGHT, new MoveObjectCommand(Plane, linalg::Vec3( 1,  0, 0), MOVE_SPEED)); // move camera right
  //inputHandler->addInputMapping(SDLK_UP,    new MoveObjectCommand(Plane, linalg::Vec3( 0,  1, 0), MOVE_SPEED)); // move camera up
  //inputHandler->addInputMapping(SDLK_DOWN,  new MoveObjectCommand(Plane, linalg::Vec3( 0, -1, 0), MOVE_SPEED)); // move camera down

  // run the game
  GameEngine theGame(inputHandler, fps);

  //theGame.addGameObject(Plane);
  theGame.run();

  return 0;
}
