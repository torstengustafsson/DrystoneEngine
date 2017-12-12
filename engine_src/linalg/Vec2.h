#pragma once

#include <cmath>
#include "linalg/Mat2.h"

/*
* Defines vectors in 2D.
* Common vector and matrix operations are supported.
*/

namespace linalg {


  // forward declarations
  class Vec3;
  class Vec4;

class Vec2 {
public:
  Vec2(float f = 0.0f);
  Vec2(float _x, float _y);
  Vec2(const Vec4& v);
  Vec2(const Vec3& v);

  Vec2 operator+(const Vec2 v) const;
  Vec2 operator-(const Vec2 v) const;
  float operator*(const Vec2 v) const; // scalar product
  Vec2 operator^(const Vec2 v) const; // cross product
  Vec2 operator*(const float f) const;
  Vec2 operator/(const float f) const;

  Vec2 normalize(); // normalizes this vector
  Vec2 getNormalized() const; // returns a normalized vector based on this
  float length() const;

  float x, y;
};

// helper functions

Vec2 operator*(float f, const Vec2 &v);

inline float length(Vec2& v) {
  return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

inline Vec2 normalize(Vec2& v) {
  v = v / length(v);
  return v;
}

} // namespace linalg
