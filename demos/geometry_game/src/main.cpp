#include "GameEngine.h"
#include "world/GameObjectFactory.h"
#include "core/inc/Log.h"
#include "PlaneHandler.h"
#include "input.h"

#include <iostream>
#include <memory>

/*
* Renders 3 planes. 2 of them have their own event handling, giving them animation.
* Animation may be paused/started using keys 1 and 2.
*/

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  InputHandler inputHandler;

  GameObject plane1 = GameObjectFactory::createPlane(0.5, 0.5);
  plane1.addEventHandler(std::make_shared<PlaneHandler>(inputHandler, Preset::PRESET1));

  GameObject plane2 = GameObjectFactory::createPlane(0.5, 0.2);
  plane2.addEventHandler(std::make_shared<PlaneHandler>(inputHandler, Preset::PRESET2));

  GameObject plane3 = GameObjectFactory::createPlane(0.1, 0.5);
  plane3.setPosition(linalg::Vec3(-0.75, 0.25, -2.0));

  GameObject plane4 = GameObjectFactory::createPlane(0.1, 0.5);
  plane4.setPosition(linalg::Vec3(0.75, 0.25, -3.0));

  // run the game
  GameEngine theGame(inputHandler, fps);
  inputHandler.addInputMapping(SDLK_ESCAPE, std::make_shared<ExitCommand>());

  theGame.addGameObject(plane1);
  theGame.addGameObject(plane2);
  theGame.addGameObject(plane3);
  theGame.addGameObject(plane4);
  theGame.run();

  return 0;
}
