#include "core/inc/Log.h"
#include "linalg/Mat4.h"
#include "linalg/Vec3.h"

#define str std::to_string

namespace linalg {

Mat4::Mat4()
  : m{ 1, 0, 0, 0,
       0, 1, 0, 0,
       0, 0, 1, 0,
       0, 0, 0, 1 } {
}

Mat4::Mat4(float f1,  float f2,  float f3,  float f4,
           float f5,  float f6,  float f7,  float f8,
           float f9,  float f10, float f11, float f12,
           float f13, float f14, float f15, float f16)
  : m{ f1,  f2,  f3,  f4,
       f5,  f6,  f7,  f8,
       f9,  f10, f11, f12,
       f13, f14, f15, f16 } {
}

Mat4::Mat4(float f)
  : m{ f, f, f, f,
       f, f, f, f,
       f, f, f, f,
       f, f, f, f } {
}

void Mat4::setTranslation(const Vec3& pos) {
  m[3]  = pos.x;
  m[7]  = pos.y;
  m[11] = pos.z;
}

void Mat4::setScale(const Vec3& scale) {
  m[0]  = scale.x;
  m[5]  = scale.y;
  m[10] = scale.z;
}

void Mat4::setOrientation(const Quat& orientation) {
  //TODO
}

Vec3 Mat4::getTranslation() const {
  return Vec3(m[3], m[7], m[11]);
}

Vec3 Mat4::getScale() const {
  return Vec3(m[0], m[5], m[10]);
}

Quat Mat4::getOrientation() const {
  // TODO
  return Quat(0,0,0,1);
}

void Mat4::print() const {
  std::string output = "{ " + str(m[0])  + ", " + str(m[1])  + ", " + str(m[2])  + ", " + str(m[3])  + ",\n" +
                       "  " + str(m[4])  + ", " + str(m[5])  + ", " + str(m[6])  + ", " + str(m[7])  + ",\n" +
                       "  " + str(m[8])  + ", " + str(m[9])  + ", " + str(m[10]) + ", " + str(m[11]) + ",\n" +
                       "  " + str(m[12]) + ", " + str(m[13]) + ", " + str(m[14]) + ", " + str(m[15]) + " }\n";
  log(output);
}

} // namespace linalg
