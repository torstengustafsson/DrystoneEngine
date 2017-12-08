#pragma once

#include <components/geometries/inc/Mesh.h>
#include "linalg/linalg.h"

#include <string>
#include <memory>

/*
* TODO: write description
*/

class GameObject {
public:
  GameObject(std::shared_ptr<Mesh> _mesh = nullptr);

  void render(const linalg::Mat4& V, const linalg::Mat4& P);

  void setTranslation(const linalg::Vec3& pos);
  void translate(const linalg::Vec3& vec);

  linalg::Vec3 getPosition() const;
  std::shared_ptr<Mesh> getMesh() const;

protected:
  // the name that will be displayed during player interaction etc.
  std::string name;

  // components
  std::shared_ptr<Mesh> mesh;
  linalg::Mat4 transform;
};
