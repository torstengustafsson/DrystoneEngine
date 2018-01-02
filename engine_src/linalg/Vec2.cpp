#include "linalg/Vec2.h"
#include "linalg/Vec3.h"
#include "linalg/Vec4.h"
#include "core/inc/Log.h"

namespace linalg {

Vec2::Vec2(float f)
  : x(f), y(f) {
}

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

Vec2 operator*(const float f, const Vec2 &v) {
  return Vec2(v.x * f, v.y * f);
}

Vec2 Vec2::operator/(const float f) const {
  return Vec2(x / f, y / f);
}

Vec2 Vec2::normalize() {
  return linalg::normalize(*this);
}

Vec2 Vec2::getNormalized() const {
  Vec2 v(*this);
  return v.normalize();
}

float Vec2::length() const {
  return linalg::length(*this);
}

float& Vec2::operator[](std::size_t i) {
  if(i < 0 || i >= 2) {
    log_verbose("Error: index out of bounds");
  }
  return i == 0 ? x : y;
}

const float& Vec2::operator[](std::size_t i) const {
  if (i < 0 || i >= 2) {
    log_verbose("Error: index out of bounds");
  }
  return i == 0 ? x : y;
}


void Vec2::print() const {
  std::string output = "{ " + to_str(x) + ", " + to_str(y) + " }\n";
  log(output);
}

} // namespace linalg
