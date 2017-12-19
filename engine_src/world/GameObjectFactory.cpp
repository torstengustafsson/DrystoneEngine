#include "world/GameObjectFactory.h"
#include "world/GameObject.h"
#include "components/Mesh.h"
#include "linalg/Vec3.h"

std::shared_ptr<GameObject> GameObjectFactory::createPlane(const float width, const float height) {
  return std::make_shared<GameObject>(std::make_shared<Mesh>(width, height));
}

// A smileyface created usign planes (like pixelart)
std::shared_ptr<GameObject> GameObjectFactory::createSmileyFace(const float size) {
  std::shared_ptr<GameObject> smiley = std::make_shared<GameObject>();

  auto eye1 = GameObjectFactory::createPlane(0.2, 0.2);
  eye1->setTranslation(linalg::Vec3(-0.3, 0.3, 0.0));
  auto eye2 = GameObjectFactory::createPlane(0.2, 0.2);
  eye2->setTranslation(linalg::Vec3(0.1, 0.3, 0.0));

  auto mouthPiece1 = GameObjectFactory::createPlane(0.1, 0.1);
  mouthPiece1->setTranslation(linalg::Vec3(-0.3, 0.0, 0.0));
  auto mouthPiece2 = GameObjectFactory::createPlane(0.1, 0.2);
  mouthPiece2->setTranslation(linalg::Vec3(-0.2, -0.1, 0.0));
  auto mouthPiece3 = GameObjectFactory::createPlane(0.2, 0.1);
  mouthPiece3->setTranslation(linalg::Vec3(-0.1, -0.2, 0.0));

  smiley->addChild(*eye1);
  smiley->addChild(*eye2);

  return eye1;
}