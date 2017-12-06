
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
  Plane(linalg::Vec3 pos, float width, float height);

  void render() override;

private:
  linalg::Vec3 positions[NUM_VERTICES];
  linalg::Vec3 normals[NUM_VERTICES];

  linalg::Mat4 transform;
  float width, height;
};
