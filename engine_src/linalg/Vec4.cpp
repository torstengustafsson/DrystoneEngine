#include "linalg/Vec4.h"

#include "linalg/Vec2.h"
#include "linalg/Vec3.h"

namespace linalg {

Vec4::Vec4(float f)
  : x(f), y(f), z(f), w(f) {
}

Vec4::Vec4(float _x, float _y, float _z, float _w)
  : x(_x), y(_y), z(_z), w(_w) {
}

Vec4::Vec4(const Vec3& v)
  : x(v.x), y(v.y), z(v.z), w(0.0f) {
}

Vec4::Vec4(const Vec2& v)
  : x(v.x), y(v.y), z(0.0f), w(0.0f) {
}

Vec4 Vec4::operator+(const Vec4 v) const {
  return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vec4 Vec4::operator-(const Vec4 v) const {
  return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

float Vec4::operator*(const Vec4 v) const {
  return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vec4 operator*(const float f, const Vec4 &v) {
  return Vec4(v.x * f, v.y * f, v.z * f, v.w *f);
}

Vec4 Vec4::operator*(const float f) const {
  return Vec4(x * f, y * f, z * f, w * f);
}

Vec4 Vec4::operator/(const float f) const {
  return Vec4(x / f, y / f, z / f, w / f);
}

Vec4 Vec4::normalize() {
  return linalg::normalize(*this);
}

Vec4 Vec4::getNormalized() const {
  Vec4 v(*this);
  return v.normalize();
}

float Vec4::length() const {
  return linalg::length(*this);
}

} // namespace linalg
