#include "linalg/Mat2.h"
#include "core/inc/Log.h"

#define str std::to_string

namespace linalg {

Mat2::Mat2()
  : m{ 1, 0,
       0, 1 } {
}

Mat2::Mat2(float f1, float f2, float f3, float f4)
  : m{ f1, f2,
       f3, f4 } {
}

Mat2::Mat2(float f)
  : m{ f, f,
       f, f } {
}

Mat2 Mat2::operator+(const Mat2 o) const {
  return Mat2( m[0] + o.m[0], m[1] + o.m[1],
               m[2] + o.m[2], m[3] + o.m[3] );
}

Mat2 Mat2::operator-(const Mat2 o) const {
  return Mat2( m[0] - o.m[0], m[1] - o.m[1],
               m[2] - o.m[2], m[3] - o.m[3] );
}

Mat2 Mat2::operator*(const Mat2 o) const {
  return Mat2(m[0] * o.m[0] + m[1] * o.m[2], m[0] * o.m[1] + m[1] * o.m[3],
              m[2] * o.m[0] + m[3] * o.m[2], m[2] * o.m[1] + m[3] * o.m[3] );
}

Mat2 Mat2::operator*(const float f) const {
  return Mat2( m[0] * f, m[1] * f,
               m[2] * f, m[3] * f );
}

Mat2 Mat2::operator/(const Mat2 o) const {
  return (*this) * o.getInverse();
}

Mat2 Mat2::operator/(const float f) const {
  return Mat2(m[0] / f, m[1] / f,
              m[2] / f, m[3] / f);
}

float Mat2::getDeterminant() const {
  return m[0] * m[3] - m[1] * m[2];
}

Mat2 Mat2::getInverse() const {
  return Mat2(); // TODO

  // check if inverse exist
  // if not, return 0 matrix
  if (getDeterminant() == 0) {
    log_verbose("Error: trying top get inverse of matrix that has no inverse!\n");
     return Mat2(0.0f);
  }

  Mat2 res;
}

void Mat2::print() const {
  std::string output = "{ " + str(m[0])  + ", " + str(m[1])  + ", " +
                              str(m[2])  + ", " + str(m[3]) + "}\n";
  log(output);
}

} // namespace linalg
