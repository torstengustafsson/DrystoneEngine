#pragma once

#include <cmath>
#include "linalg/Vector.h"
#include "linalg/Quaternion.h"

/*
* Defines matrices in 2x2, 3x3 and 4x4 format.
* Common matrix, vector and quaternion operations are supported.
*/

namespace linalg {

// forward declarations
class Vec3;
class Quat;

class Mat2 {
public:
  Mat2(); // identity matrix
  Mat2(float f1, float f2, 
       float f3, float f4);
  Mat2(float f);

  Mat2 operator+(const Mat2 v) const;
  Mat2 operator-(const Mat2 v) const;
  Mat2 operator*(const Mat2 v) const;
  Mat2 operator*(const float f) const;
  Mat2 operator/(const Mat2 f) const;
  Mat2 operator/(const float f) const;

  float getDeterminant() const;
  Mat2 getInverse() const;

  float m[4];
};

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

  float m[9];
};

class Mat4 {
public:
  Mat4(); // identity matrix
  Mat4(float f1,  float f2,  float f3,  float f4,
       float f5,  float f6,  float f7,  float f8,
       float f9,  float f10, float f11, float f12,
       float f13, float f14, float f15, float f16);
  Mat4(float f);

  void setTranslation(const Vec3& pos);
  void setScale(const Vec3& scale);
  void setOrientation(const Quat& orientation);

  Vec3 getTranslation() const;
  Vec3 getScale() const;
  Quat getOrientation() const;

  void print() const;

  float m[16];
};

inline Mat2 operator*(float f, const Mat2 &mat) {
  return mat * f;
}


// helper functions

//inline Mat3 operator*(float f, const Mat3 &v);

} // namespace linalg
