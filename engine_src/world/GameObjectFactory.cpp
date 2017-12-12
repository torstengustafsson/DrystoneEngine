#include "world/GameObjectFactory.h"
#include "components\geometries\Plane.h"

std::shared_ptr<GameObject> GameObjectFactory::createPlane(const float width, const float height) {
  return std::make_shared<GameObject>(std::make_shared<Plane>(width, height));
}