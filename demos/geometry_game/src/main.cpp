#include "GameEngine.h"
#include "world/GameObjectFactory.h"
#include "core/inc/Log.h"
#include "PlaneHandler.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  const float MOVE_SPEED = 0.1f;

  GameObject plane1 = GameObjectFactory::createPlane(0.5, 0.5);
  plane1.addEventHandler(std::make_shared<PlaneHandler>(0.01));

  GameObject plane2 = GameObjectFactory::createPlane(0.5, 0.2);
  plane2.setPosition(linalg::Vec3(-0.25, -0.25, 0.0));
  plane2.addEventHandler(std::make_shared<PlaneHandler>(0.015));


  // run the game
  GameEngine theGame(fps);
  theGame.addGameObject(plane1);
  theGame.addGameObject(plane2);
  theGame.run();

  return 0;
}
