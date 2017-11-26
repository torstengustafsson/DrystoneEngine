#include <iostream>
#include "linalg/Matrix.h"

namespace linalg {


/// *** Mat2 *** ///

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
     std::cout << "Error: trying top get inverse of matrix that has no inverse!\n";
     return Mat2(0.0f);
  }

  Mat2 res;
}


/// *** Mat3 *** ///

Mat3::Mat3()
  : m{ 1, 0, 0,
       0, 1, 0,
       0, 0, 1 } {
}

Mat3::Mat3(float f1, float f2, float f3,
           float f4, float f5, float f6,
           float f7, float f8, float f9)
  : m{ f1, f2, f3,
       f4, f5, f6,
       f7, f8, f9 } {
}

Mat3::Mat3(float f)
  : m{ f, f, f,
       f, f, f,
       f, f, f } {
}


/// *** Mat4 *** ///

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

Vec3 Mat4::getTranslation() const {
  return Vec3(m[3], m[7], m[11]);
}

Vec3 Mat4::getScale() const {
  return Vec3(m[0], m[5], m[10]);
}

} // namespace linalg
