#pragma once

#include <cmath>

/*
* Defines vectors in 2D, 3D and 4D.
* Common vector and matrix operations are supported.
*/

namespace linalg {

// forward declarations
class Vec2; 
class Vec3;

class Vec4 {
public:
  Vec4(float f = 0.0f);
  Vec4(float _x, float _y, float _z, float _w);
  Vec4(const Vec3& v);
  Vec4(const Vec2& v);

  Vec4 operator+(const Vec4 v) const;
  Vec4 operator-(const Vec4 v) const;
  float operator*(const Vec4 v) const; // scalar product
  /* cross product in 4 dimensions does not really exist */
  Vec4 operator*(const float f) const;
  Vec4 operator/(const float f) const;

  Vec4 normalize(); // normalizes this vector
  Vec4 getNormalized() const; // returns a normalized vector based on this
  float length() const;

  float x, y, z, w;
};


// helper functions

Vec4 operator*(float f, const Vec4 &v);

inline float length(const Vec4& v) {
  return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
}

inline Vec4 normalize(Vec4& v) {
  v = v / length(v);
  return v;
}

} // namespace linalg
