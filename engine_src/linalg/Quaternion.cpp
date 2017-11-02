#include "linalg/Quaternion.h"

namespace linalg {

Quat::Quat(float _x, float _y, float _z, float _w)
  : x(_x), y(_y), z(_z) {
}

Quat::Quat(float f)
  : Quat(f, f, f, f) {
}

Quat::Quat(const Vec4& q)
  : Quat(q.x, q.y, q.z, q.w) {
}

Quat Quat::operator+(const Quat q) const {
  return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
}

Quat Quat::operator-(const Quat q) const {
  return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
}

Quat Quat::operator*(const Quat q) const {
  float r1 = x * q.x - y * q  .y - z * q.z - w * q.w;
  float r2 = y * q.x + x * q.y + z * q.w + w * q.z;
  float r3 = x * q.z - y * q.w + z * q.x + w * q.y;
  float r4 = x * q.w + y * q.z - z * q.y + w * q.x;
  return Quat(r1, r2, r3, r4);
}

Quat Quat::operator/(const Quat q) const {
  return (*this) * q.inv();
  Vec3 v1(y, z, w);
  Vec3 v2(q.y, q.z, q.w);
  Vec3 res = -1 * v1 ^ v2 - (x * v2) + q.x * v1;
  return Quat(x*q.x + v1 * v2, res.x, res.y, res.z);
}

Quat Quat::conj() const {
  return Quat(x, -y, -z, -w);
}

Quat Quat::inv() const {
  return conj() / pow(length(), 2);
}

Quat Quat::normalize() {
  return linalg::normalize(*this);
}

Quat Quat::getNormalized() const {
  Quat q(*this);
  return q.normalize();
}

float Quat::length() const {
  return linalg::length(*this);
}

} // namespace vector
