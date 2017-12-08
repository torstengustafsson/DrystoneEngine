#pragma once

#include "linalg/Vector.h"
#include "world/GameObject.h"
#include "input/InputHandler.h"

#include <memory>

class MoveObjectCommand : public InputCommand {
public:
  MoveObjectCommand(std::shared_ptr<GameObject> _object, linalg::Vec3 _direction, float _speed);
  void execute() override;
private:
  void print();

  std::shared_ptr<GameObject> object;
  linalg::Vec3 direction;
};
