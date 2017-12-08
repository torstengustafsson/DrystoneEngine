
#include <stdint.h>
#include "components/geometries/inc/Mesh.h"
#include "linalg/linalg.h"

#define NUM_VERTICES 4

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

  float width, height;
};
