#include "GameEngine.h"
#include "components/geometries/Plane.h"
#include "core/Log.h"
#include "input.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  const float CAM_SPEED = 10.0f;

  log("hej");

  // add input
  std::shared_ptr<InputHandler> inputHandler = std::make_shared<InputHandler>();
  inputHandler->addInputMapping(SDLK_LEFT,  new MoveCameraCommand(linalg::Vec4(-1,  0, 0, 1), CAM_SPEED)); // move camera left
  inputHandler->addInputMapping(SDLK_RIGHT, new MoveCameraCommand(linalg::Vec4( 1,  0, 0, 1), CAM_SPEED)); // move camera right
  inputHandler->addInputMapping(SDLK_UP,    new MoveCameraCommand(linalg::Vec4( 0,  1, 0, 1), CAM_SPEED)); // move camera up
  inputHandler->addInputMapping(SDLK_DOWN,  new MoveCameraCommand(linalg::Vec4( 0, -1, 0, 1), CAM_SPEED));  // move camera down
  inputHandler->addInputMapping(SDLK_z,     new ZoomCameraCommand(true, CAM_SPEED));                       // zoom in
  inputHandler->addInputMapping(SDLK_x,     new ZoomCameraCommand(false, CAM_SPEED));                      // zoom out

  // run the game
  GameEngine theGame(inputHandler, fps);
  theGame.addGameObject(std::make_shared<GameObject>(std::make_shared<Plane>()));
  theGame.run();

  std::cin.ignore();
  return 0;
}
