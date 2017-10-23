#pragma once

#include "datastructures/inc/Vector.h"

/*
* TODO: write description
*/

class InputCommand {
public:
  virtual void execute() = 0;
};

class ChangeBGColorCommand : public InputCommand {
public:
  ChangeBGColorCommand(Vec4 _color);
  void execute() override;
private:
  Vec4 color;
};
