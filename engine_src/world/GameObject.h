#pragma once

#include "linalg/Mat4.h"

#include <string>
#include <vector>
#include <memory>

/*
* The basic object that all ingame objects are made up of. 
* Based on the component pattern.
* Each GameObject may have other GameObjects as its children.
*/

// forward declarations
namespace linalg {
  class Vec3;
}
class Mesh;

class GameObject {
public:
  GameObject(std::shared_ptr<Mesh> _mesh = nullptr);

  void render(const linalg::Mat4& frameOfReference, const linalg::Mat4& View, const linalg::Mat4& Projection);

  void setTranslation(const linalg::Vec3& pos);
  void translate(const linalg::Vec3& vec);

  linalg::Vec3 getPosition() const;
  std::shared_ptr<Mesh> getMesh() const;

 // std::vector<GameObject> getChildren();
 // void addChild(std::shared_ptr<GameObject> child);
  void addChild(const GameObject& child);
//  void removeChild(GameObject child);

private:
  // the name that will be displayed during player interaction etc.
  std::string name;

  // components
  std::shared_ptr<Mesh> mesh;
  linalg::Mat4 transform;

  std::vector<GameObject> children;
};
