#pragma once

/*
* Defines matrices in 2x2 format.
* Common matrix operations are supported.
*/

namespace linalg {

class Mat2 {
public:
  Mat2(); // identity matrix
  Mat2(float f1, float f2,
       float f3, float f4);
  Mat2(float f);

  Mat2 operator+(const Mat2 v) const;
  Mat2 operator-(const Mat2 v) const;
  Mat2 operator*(const Mat2 v) const;
  Mat2 operator*(const float f) const;
  Mat2 operator/(const Mat2 f) const;
  Mat2 operator/(const float f) const;

  float getDeterminant() const;
  Mat2 getInverse() const;

  void print() const;

  float m[4];
};

} // namespace linalg
