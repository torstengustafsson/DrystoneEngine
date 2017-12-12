#pragma once

#include <cmath>

/*
* Defines matrices in 3x3 format.
* Common matrix, vector and quaternion operations are supported.
*/

namespace linalg {

// forward declarations
class Vec3;
class Quat;

class Mat3 {
public:
  Mat3(); // identity matrix
  Mat3(float f1, float f2, float f3,
       float f4, float f5, float f6,
       float f7, float f8, float f9);
  Mat3(float f);

  //void translate(const Vec3& p);
  //void translate(float x, float y);
  //void scale(const Vec3& s);
  //void scale(const float s);
  //void rotX(const float a);
  //void rotY(const float a);
  //void rotZ(const float a);
  //void rotate(const float angle, const Vec2& axis);
  //void rotate(const Quat& q);

  //Mat3 operator+(const Mat3 v) const;
  //Mat3 operator-(const Mat3 v) const;
  //Mat3 operator*(const Mat3 v) const;
  //Mat3 operator*(const float f) const;
  //Mat3 operator/(const Mat3 f) const;
  //Mat3 operator/(const float f) const;

  //float getDeterminant();
  //float inv();

  void print() const;

  float m[9];
};

// helper functions

//inline Mat3 operator*(float f, const Mat3 &v);

} // namespace linalg
