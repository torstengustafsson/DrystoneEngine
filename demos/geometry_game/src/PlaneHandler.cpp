#include "PlaneHandler.h"
#include "components/Mesh.h"
#include "linalg/linalg.h"
#include "input/inc/InputCommand.h"
#include "core/inc/Log.h"

#include <string>
#include <iomanip> // setprecision
#include <sstream> // stringstream

PlaneHandler::PlaneHandler(const float& incr) {
  animationVal = 0.0;
  animationIncr = incr;
}

void PlaneHandler::update() {
  Mesh* mesh = gameObject->getMesh();

  mesh->translate(linalg::Vec3(0.0, animationIncr, 0.0));
  mesh->setScale(animationVal);
  mesh->rotX(linalg::PI / 2.0 * animationVal);
  animationVal += animationIncr;
}
