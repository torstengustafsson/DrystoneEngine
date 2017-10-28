#pragma once

#include "datastructures/Vector.h"

/*
* TODO: write description
*/

class InputCommand {
public:
  virtual void execute() = 0;
};

class ChangeBGColorCommand : public InputCommand {
public:
  ChangeBGColorCommand(vector::Vec4 _color);
  void execute() override;
private:
  vector::Vec4 color;
};
