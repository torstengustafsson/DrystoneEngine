#include "linalg/Vec3.h"

#include "linalg/Vec2.h"
#include "linalg/Vec4.h"

namespace linalg {

Vec3::Vec3(float f)
  : x(f), y(f), z(f) {
}

Vec3::Vec3(float _x, float _y, float _z)
  : x(_x), y(_y), z(_z) {
}

Vec3::Vec3(const Vec4& v)
  : x(v.x), y(v.y), z(v.z) {
}

Vec3::Vec3(const Vec2& v)
  : x(v.x), y(v.y), z(0.0f) {
}

Vec3 Vec3::operator+(const Vec3 v) const {
  return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3 v) const {
  return Vec3(x - v.x, y - v.y, z - v.z);
}

float Vec3::operator*(const Vec3 v) const {
  return x * v.x + y * v.y + z * v.z;
}

Vec3 operator*(const float f, const Vec3 &v) {
  return Vec3(v.x * f, v.y * f, v.z * f);
}

Vec3 Vec3::operator^(const Vec3 v) const {
  float _x = y * v.z - z * v.y;
  float _y = z * v.x - x * v.z;
  float _z = x * v.y - y * v.x;
  return Vec3(_x, _y, _z);
}

Vec3 Vec3::operator*(const float f) const {
  return Vec3(x * f, y * f, z * f);
}

Vec3 Vec3::operator/(const float f) const {
  return Vec3(x / f, y / f, z / f);
}

Vec3 Vec3::normalize() {
  return linalg::normalize(*this);
}

Vec3 Vec3::getNormalized() const {
  Vec3 v(*this);
  return v.normalize();
}

float Vec3::length() const {
  return linalg::length(*this);
}

} // namespace linalg
