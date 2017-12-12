#pragma once

#include <cmath>
#include "linalg/Mat3.h"

/*
* Defines vectors in 2D, 3D and 4D.
* Common vector and matrix operations are supported.
*/

namespace linalg {

// forward declarations
class Vec2;
class Vec4;

class Vec3 {
public:
  Vec3(float f = 0.0f);
  Vec3(float _x, float _y, float _z);
  Vec3(const Vec4& v);
  Vec3(const Vec2& v);

  Vec3 operator+(const Vec3 v) const;
  Vec3 operator-(const Vec3 v) const;
  float operator*(const Vec3 v) const; // scalar product
  Vec3 operator^(const Vec3 v) const; // cross product
  Vec3 operator*(const float f) const;
  Vec3 operator/(const float f) const;

  Vec3 normalize(); // normalizes this vector
  Vec3 getNormalized() const; // returns a normalized vector based on this
  float length() const;

  float x, y, z;
};

// helper functions

Vec3 operator*(float f, const Vec3 &v);

inline float length(Vec3& v) {
  return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

inline Vec3 normalize(Vec3& v) {
  v = v / length(v);
  return v;
}

} // namespace linalg
