#include "datastructures/inc/Vector.h"

/// *** Vec2 *** ///

Vec2::Vec2(float _x, float _y) 
  : x(_x),
    y(_y) {
}


std::initializer_list<float> Vec2::operator()() {
  return { x, y };
}

/// *** Vec3 *** ///

Vec3::Vec3(float _x, float _y, float _z)
  : Vec2(_x, _y),
    z(_z) {
}

std::initializer_list<float> Vec3::operator()() {
  return { x, y, z };
}

/// *** Vec4 *** ///

Vec4::Vec4(float _x, float _y, float _z, float _w)
  : Vec3(_x, _y, _z),
    w(_w) {
}

std::initializer_list<float> Vec4::operator()() {
  return { x, y, z, w };
}
