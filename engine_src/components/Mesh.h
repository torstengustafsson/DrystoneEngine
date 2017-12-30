#pragma once 

#include "linalg/Vec3.h"
#include "linalg/Mat4.h"

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

class Mesh {
public:
  Mesh();
  Mesh(float width, float height);

  void render(const linalg::Mat4& V, const linalg::Mat4& P) const;

  linalg::Mat4 transform;

  float angle; // TODO: should be a quat or something, for general orientations
  linalg::Vec3 scale;
  linalg::Vec3 position;

private:
  linalg::Vec3 positions[NUM_VERTICES];
  linalg::Vec3 normals[NUM_VERTICES];

  GLfloat square[POINTS][FLOATSPERPOINT];

  float width, height;
};
