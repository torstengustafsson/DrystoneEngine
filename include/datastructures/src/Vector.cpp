#include <cmath>
#include "datastructures/inc/Vector.h"

namespace vector {

/// *** Vec2 *** ///

Vec2::Vec2(float _x, float _y) 
  : x(_x), y(_y) {
}

Vec2::Vec2(const Vec4& v)
  : x(v.x), y(v.y) {
}

Vec2::Vec2(const Vec3& v)
  : x(v.x), y(v.y) {
}

Vec2 Vec2::operator+(const Vec2 v) const {
  return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2 v) const {
  return Vec2(x - v.x, y - v.y);
}

float Vec2::operator*(const Vec2 v) const {
  return x * v.x + y * v.y;
}

Vec2 Vec2::operator^(const Vec2 v) const {
  return Vec2(x * v.y, y * v.x);
}

Vec2 Vec2::operator*(const float f) const {
  return Vec2(x * f, y * f);
}

Vec2 Vec2::operator/(const float f) const {
  return Vec2(x / f, y / f);
}

Vec2 Vec2::normalize() {
  return vector::normalize(*this);
}

Vec2 Vec2::getNormalized() const {
  Vec2 v(*this);
  return v.normalize();
}

float Vec2::length() const {
  return vector::length(*this);
}


/// *** Vec3 *** ///

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
  return vector::normalize(*this);
}

Vec3 Vec3::getNormalized() const {
  Vec3 v(*this);
  return v.normalize();
}

float Vec3::length() const {
  return vector::length(*this);
}


/// *** Vec4 *** ///

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

Vec4 Vec4::operator*(const float f) const {
  return Vec4(x * f, y * f, z * f, w * f);
}

Vec4 Vec4::operator/(const float f) const {
  return Vec4(x / f, y / f, z / f, w / f);
}

Vec4 Vec4::normalize() {
  return vector::normalize(*this);
}

Vec4 Vec4::getNormalized() const {
  Vec4 v(*this);
  return v.normalize();
}

float Vec4::length() const {
  return vector::length(*this);
}

} // namespace vector
