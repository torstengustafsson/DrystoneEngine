#pragma once

/*
* Used as a component to render meshes
*/

// forward declarations
namespace linalg {
class Mat4;
}

class Mesh {
public:
  virtual void render(const linalg::Mat4& M, const linalg::Mat4& V, const linalg::Mat4& P) = 0;
};
