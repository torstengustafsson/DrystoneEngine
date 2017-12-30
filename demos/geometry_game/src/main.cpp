#include "GameEngine.h"
#include "world/GameObjectFactory.h"
#include "core/inc/Log.h"
#include "PlaneHandler.h"

#include <iostream>
#include <memory>

/*
* Renders 3 planes. 2 of them have their own event handling, giving them animation.
* Animation may be paused/started using keys 1 and 2.
*/

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  std::shared_ptr<InputHandler> inputHandler = std::make_shared<InputHandler>();

  GameObject plane1 = GameObjectFactory::createPlane(0.5, 0.5);
  plane1.addEventHandler(std::make_shared<PlaneHandler>(inputHandler, Preset::PRESET1));

  GameObject plane2 = GameObjectFactory::createPlane(0.5, 0.2);
  plane2.addEventHandler(std::make_shared<PlaneHandler>(inputHandler, Preset::PRESET2));

  GameObject plane3 = GameObjectFactory::createPlane(0.1, 0.5);
  plane3.setPosition(linalg::Vec3(0.75, 0.25, 0.0));

  // run the game
  GameEngine theGame(inputHandler, fps);
  theGame.addGameObject(plane1);
  theGame.addGameObject(plane2);
  theGame.addGameObject(plane3);
  theGame.run();

  return 0;
}
