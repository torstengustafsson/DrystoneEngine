#pragma once

#include <cmath>
#include <initializer_list>

/*
* TODO: write description
*/

namespace vector {

// forward declarations
class Vec2; 
class Vec3;
class Vec4;

class Vec2 {
public:
  Vec2(float x = 0.0f, float y = 0.0f);
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

class Vec3 {
public:
  Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
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

class Vec4 {
public:
  Vec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
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

inline float length(Vec2& v) {
  return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

inline float length(Vec3& v) {
  return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

inline float length(const Vec4& v) {
  return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
}

inline Vec2 normalize(Vec2& v) {
  v = v / length(v);
  return v;
}

inline Vec3 normalize(Vec3& v) {
  v = v / length(v);
  return v;
}

inline Vec4 normalize(Vec4& v) {
  v = v / length(v);
  return v;
}

} // namespace vector