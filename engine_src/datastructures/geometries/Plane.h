
#include <stdint.h>
#include "datastructures/geometries/inc/Mesh.h"
#include "linalg/Vector.h"

#define NUM_VERTICES 4

class Plane : public Mesh {
public:
  Plane();

  void render() override;
private:
  linalg::Vec3 positions[NUM_VERTICES];
  linalg::Vec3 normals[NUM_VERTICES];
};
