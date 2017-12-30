#include "world/GameObjectFactory.h"
#include "world/GameObject.h"
#include "components/Mesh.h"
#include "components/ComponentManager.h"
#include "linalg/Vec3.h"

GameObject GameObjectFactory::createPlane(const float width, const float height) {
  return GameObject(GO_PROTOTYPE, new Mesh(width, height));
}
