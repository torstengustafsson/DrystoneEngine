#include "PlaneHandler.h"
#include "components/Mesh.h"
#include "linalg/linalg.h"
#include "input.h"
#include "core/inc/Log.h"

#include <string>
#include <iomanip> // setprecision
#include <sstream> // stringstream

PlaneHandler::PlaneHandler(std::shared_ptr<InputHandler> _inputHandler, Preset _preset) 
  : active(true),
    animationVal(0.0),
    preset(_preset) {

  setInputHandler(_inputHandler);

  if (preset == Preset::PRESET1) {
    addInputMapping(SDLK_1, std::make_shared<ActivateCommand>(this));
  }
  else if (preset == Preset::PRESET2) {
    addInputMapping(SDLK_2, std::make_shared<ActivateCommand>(this));
  }
}

void PlaneHandler::update() {
  if (!active) {
    return;
  }

  Mesh* mesh = gameObject->getMesh();

  switch (preset) {
  case Preset::PRESET1:
    mesh->setPosition(linalg::Vec3(0.2 * sin(animationVal), 0.0, -7.0 + 5.0 * sin(animationVal)));
    mesh->setScale(0.5 + 0.1 * sin(animationVal));
    mesh->setScale(1.0);
    mesh->rotX(3.0 * linalg::PI * sin(animationVal));
    animationVal += 0.1;
    break;
  case Preset::PRESET2:
    mesh->setPosition(linalg::Vec3(-0.2, 0.5 * 0.5 * cos(animationVal) - 0.25, -1.5 + cos(animationVal)));
    mesh->setScale(0.5 + 0.1 * cos(animationVal));
    mesh->rotX(linalg::PI * cos(animationVal));
    animationVal += 0.1;
    break;
  }
}
