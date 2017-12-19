#pragma once 

#include "linalg/Vec3.h"
#include <stdint.h>
#include "GL/glew.h"

#define NUM_VERTICES 4
#define POINTS 6
#define FLOATSPERPOINT 3

/*
* Component storing the renderable data of a 3D mesh, used by a game object.
*
* TODO: should be able to create vertex array directly, or load from file.
*       currently hardcoded as a plane.
*/

// forward declarations
namespace linalg {
  class Mat4;
}

class Mesh {
public:
  Mesh();
  Mesh(float width, float height);

  void render(const linalg::Mat4& M, const linalg::Mat4& V, const linalg::Mat4& P);

private:
  linalg::Vec3 positions[NUM_VERTICES];
  linalg::Vec3 normals[NUM_VERTICES];

  GLfloat square[POINTS][FLOATSPERPOINT];

  float width, height;
};
