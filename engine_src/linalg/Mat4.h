#pragma once

/*
* Defines matrices in 4x4 format.
* Common matrix, vector and quaternion operations are supported.
*/

namespace linalg {

// forward declarations
class Vec3;
class Vec4;
class Quat;

class Mat4 {
public:
  Mat4(); // identity matrix
  Mat4(float f1,  float f2,  float f3,  float f4,
       float f5,  float f6,  float f7,  float f8,
       float f9,  float f10, float f11, float f12,
       float f13, float f14, float f15, float f16);
  Mat4(float f);

  void setTranslation(const Vec3& pos);
  void setScale(const Vec3& scale);
  void setOrientation(const Quat& orientation);

  void translate(const Vec3& vec);

  void rotX(const float& angle);
  void rotY(const float& angle);
  void rotZ(const float& angle);

  Vec3 getTranslation() const;
  Vec3 getScale() const;
  Quat getOrientation() const;

  void multiply(const Mat4& other);

  Mat4& operator*(const Mat4& rhs) const;
  bool operator==(const Mat4& rhs);

  void print() const;

  float m[16];
};

// helper functions

} // namespace linalg
