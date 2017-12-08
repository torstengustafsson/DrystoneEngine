#pragma once

#include "linalg/Vector.h"
#include <cmath>

/*
* Defines quaternions with common operations.
* Note that quaternions that represent rotations should 
* always be normalized. This is not checked automatically 
* by this library, so its up the developer to make sure 
* it's correct.
*/

namespace linalg {

class Quat {
public:
  Quat(float _x, float _y, float _z, float _w);
  Quat(float f);
//  Quat(const Vec4& v); // TODO: why does this not compile? 

  Quat operator+(const Quat q) const;
  Quat operator-(const Quat q) const;
  Quat operator*(const Quat q) const;
  Quat operator/(const Quat q) const; // quaternion division is the same as multiplying with the inverse

  Quat conj() const; // returns the conjugate of this quaternion
  Quat inv() const; // returns the inverse of this quaternion
  Quat normalize(); // normalizes this quaternion
  Quat getNormalized() const; // returns a normalized quaternion based on this
  float length() const;

  float x, y, z, w;
};

// helper functions

inline float length(const Quat& q) {
  return sqrt(pow(q.x, 2) + pow(q.y, 2) + pow(q.z, 2) + pow(q.w, 2));
}

inline Quat normalize(Quat& q) {
  q = q / length(q);
  return q;
}

} // namespace linalg
