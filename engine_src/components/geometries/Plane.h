
#include <stdint.h>
#include "components/geometries/inc/Mesh.h"
#include "opengl/shader/Shader.h"
#include "linalg/linalg.h"

#define NUM_VERTICES 4
#define POINTS 6
#define FLOATSPERPOINT 3

/*
* TODO: write description
*/

class Plane : public Mesh {
public:
  Plane();
  Plane(float width, float height);

  void render(const linalg::Mat4& M, const linalg::Mat4& V, const linalg::Mat4& P) override;

private:
  linalg::Vec3 positions[NUM_VERTICES];
  linalg::Vec3 normals[NUM_VERTICES];

  GLfloat square[POINTS][FLOATSPERPOINT];

  float width, height;
};
