#include "input.h"
#include "core/inc/Globals.h"
#include "GL/glew.h"
#include "core/inc/Log.h"

ActivateCommand::ActivateCommand(PlaneHandler* planeToActivate)
  : plane(planeToActivate) {
}

void ActivateCommand::execute() {
  plane->active = !plane->active;
}

void ExitCommand::execute() {
  Globals::quit = true;
}
