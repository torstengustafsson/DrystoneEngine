#include "world/GameObjectFactory.h"
#include "world/GameObject.h"
#include "components/Mesh.h"
#include "components/ComponentManager.h"
#include "linalg/Vec3.h"

GameObject GameObjectFactory::createPlane(const float width, const float height) {
  return ComponentManager::addGameObject(Mesh(width, height));
}
