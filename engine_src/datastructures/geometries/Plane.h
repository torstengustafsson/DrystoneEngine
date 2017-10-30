
#include <stdint.h>
#include "datastructures/geometries/inc/Mesh.h"
#include "datastructures/Vector.h"

#define NUM_VERTICES 4

class Plane : public Mesh {
public:
  Plane();

  void render() override;
private:
  vector::Vec3 positions[NUM_VERTICES];
  vector::Vec3 normals[NUM_VERTICES];
};
