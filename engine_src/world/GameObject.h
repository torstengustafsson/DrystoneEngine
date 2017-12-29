#pragma once

#include "linalg/Mat4.h"
#include "core/util/UuidGenerator.h"

#include <string>
#include <vector>
#include <memory>

/*
* The basic object that all ingame objects are made up of. 
* Based on the component pattern.
* TODO: Each GameObject may have other GameObjects as its children.
*/

// forward declarations
namespace linalg {
  class Vec3;
}
class Mesh;

class GameObject {
public:
  GameObject(const int& _index, Mesh* _mesh = nullptr);
  ~GameObject();

  void setTranslation(const linalg::Vec3& pos);
  void translate(const linalg::Vec3& vec);

  linalg::Vec3 getPosition() const;
  const Mesh* getMesh() const;

  void addChild(const GameObject& child);

private:
  std::string name;

  // used to reference components. 
  // based on index in componentmanager array.
  const int index;

  // references to components are stored here. The actual component objects are 
  // managed by the ComponentManager class.
  // raw pointers used for performance-heavy tasks (main loop).
  Mesh* mesh;

  // transform is shared with components
  std::shared_ptr<linalg::Mat4> transform;

  //std::vector<GameObject> children;
};
