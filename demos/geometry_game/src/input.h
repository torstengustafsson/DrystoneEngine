#pragma once

#include "input/inc/InputCommand.h"
#include "PlaneHandler.h"

class ActivateCommand : public InputCommand {
public:
  ActivateCommand(PlaneHandler* planeToActivate);
  void execute() override;
private:
  PlaneHandler* plane;
};
