#include "GameEngine.h"
#include "components/geometries/Plane.h"
#include "core/inc/Log.h"
#include "input.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  const float MOVE_SPEED = 0.1f;

  auto thePlane = std::make_shared<GameObject>(std::make_shared<Plane>(0.5, 0.5));

  // add input
  std::shared_ptr<InputHandler> inputHandler = std::make_shared<InputHandler>();
  inputHandler->addInputMapping(SDLK_LEFT,  new MoveObjectCommand(thePlane, linalg::Vec3(-1,  0, 0), MOVE_SPEED)); // move camera left
  inputHandler->addInputMapping(SDLK_RIGHT, new MoveObjectCommand(thePlane, linalg::Vec3( 1,  0, 0), MOVE_SPEED)); // move camera right
  inputHandler->addInputMapping(SDLK_UP,    new MoveObjectCommand(thePlane, linalg::Vec3( 0,  1, 0), MOVE_SPEED)); // move camera up
  inputHandler->addInputMapping(SDLK_DOWN,  new MoveObjectCommand(thePlane, linalg::Vec3( 0, -1, 0), MOVE_SPEED)); // move camera down

  // run the game
  GameEngine theGame(inputHandler, fps);

  theGame.addGameObject(thePlane);
  theGame.run();

  std::cin.ignore();
  return 0;
}
