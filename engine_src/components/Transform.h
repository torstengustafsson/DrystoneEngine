
#include <stdint.h>
#include "linalg/linalg.h"

#define NUM_VERTICES 4

/*
* TODO: write description
*/

class Transform {
public:
  Transform();
  Transform(linalg::Vec3 pos, linalg::Quat orientation);

  void setTranslation(const linalg::Vec3& pos);
  void setScale(const linalg::Vec3& scale);
  void setOrientation(const linalg::Quat orientation);

  linalg::Vec3 getTranslation() const;
  linalg::Vec3 getScale() const;

private:

  linalg::Mat4 transform;
};
