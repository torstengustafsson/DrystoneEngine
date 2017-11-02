#include "GameEngine.h"
#include "input.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {

  int fps = argc > 1 ? fps = std::stoi(argv[1]) : 10;

  std::shared_ptr<InputHandler> inputHandler = std::make_shared<InputHandler>();
  inputHandler->addInputMapping(SDLK_r, new ChangeBGColorCommand(linalg::Vec4(1, 0, 0, 1)));
  inputHandler->addInputMapping(SDLK_g, new ChangeBGColorCommand(linalg::Vec4(0, 1, 0, 1)));
  inputHandler->addInputMapping(SDLK_b, new ChangeBGColorCommand(linalg::Vec4(0, 0, 1, 1)));

  GameEngine theGame(inputHandler, fps);
  theGame.run();

  return 0;
}
