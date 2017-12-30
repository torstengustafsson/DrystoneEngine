#include "input.h"
#include "GL/glew.h"
#include "input/inc/InputCommand.h"
#include "core/inc/Log.h"

ActivateCommand::ActivateCommand(PlaneHandler* planeToActivate)
  : plane(planeToActivate) {
}

void ActivateCommand::execute() {
  plane->active = !plane->active;
}
