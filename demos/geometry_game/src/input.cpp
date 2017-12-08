#include "input.h"
#include "input/inc/InputCommand.h"
#include "core/inc/Log.h"

#include <string>
#include <iomanip> // setprecision
#include <sstream> // stringstream

MoveObjectCommand::MoveObjectCommand(std::shared_ptr<GameObject> _object, linalg::Vec3 _direction, float _speed)
  : object(_object),
    direction(_direction * _speed) {
}

void MoveObjectCommand::execute() {
  print();
  object->translate(direction);
}

void MoveObjectCommand::print() {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << direction.getNormalized().x << ", " <<
    std::fixed << std::setprecision(2) << direction.getNormalized().y << ", " <<
    std::fixed << std::setprecision(2) << direction.getNormalized().z << ", ";
  std::string dirString = stream.str();

  log("Moving object in direction: (" + dirString + ")");
}
