#include "linalg/Mat4.h"
#include "linalg/Vec3.h"
#include "linalg/Vec4.h"
#include "linalg/Quaternion.h"
#include "core/inc/Log.h"

#define SIZE 4

namespace linalg {

Mat4::Mat4()
  : m{ 1, 0, 0, 0,
       0, 1, 0, 0,
       0, 0, 1, 0,
       0, 0, 0, 1 } {
}

Mat4::Mat4(float f1,  float f2,  float f3,  float f4,
           float f5,  float f6,  float f7,  float f8,
           float f9,  float f10, float f11, float f12,
           float f13, float f14, float f15, float f16)
  : m{ f1,  f2,  f3,  f4,
       f5,  f6,  f7,  f8,
       f9,  f10, f11, f12,
       f13, f14, f15, f16 } {
}

Mat4::Mat4(float f)
  : m{ f, f, f, f,
       f, f, f, f,
       f, f, f, f,
       f, f, f, f } {
}

const Mat4 Mat4::MakeTranslation(const Vec3& pos) {
  Mat4 m;
  m.m[3]  = pos.x;
  m.m[7]  = pos.y;
  m.m[11] = pos.z;
  return m;
}

const Mat4 Mat4::MakeScale(const Vec3& scale) {
  Mat4 m;
  m.m[0]  = scale.x;
  m.m[5]  = scale.y;
  m.m[10] = scale.z;
  return m;
}

const Mat4 Mat4::MakeScale(const float& scale) {
  return MakeScale(Vec3(scale, scale, scale));
}

const Mat4 Mat4::MakeRotX(const float& angle) {
  return Mat4( 1, 0,           0,          0,
               0, cos(angle), -sin(angle), 0,
               0, sin(angle),  cos(angle), 0,
               0, 0,           0,          1 );
}

const Mat4 Mat4::MakeRotY(const float& angle) {
  return Mat4( cos(angle), 0, sin(angle), 0,
               0,          1, 0,          0,
              -sin(angle), 0, cos(angle), 0,
               0,          0, 0,          1 );
}

const Mat4 Mat4::MakeRotZ(const float& angle) {
  return Mat4( cos(angle), -sin(angle), 0, 0,
               sin(angle),  cos(angle), 0, 0,
               0,           0,          1, 0,
               0,           0,          0, 1 );
}

const Mat4 Mat4::MakeOrientation(const Quat& orientation) {
  // TODO: identity matrix for now
  return Mat4();
}

//void Mat4::setTranslation(const Vec3& pos) {
//  m[3]  = pos.x;
//  m[7]  = pos.y;
//  m[11] = pos.z;
//}
//
//void Mat4::setScale(const Vec3& scale) {
//  m[0]  = scale.x;
//  m[5]  = scale.y;
//  m[10] = scale.z;
//}
//
//void Mat4::setScale(const float& scale) {
//  setScale(Vec3(scale, scale, scale));
//}
//
//void Mat4::setOrientation(const Quat& orientation) {
//  //TODO
//}
//
//void Mat4::translate(const Vec3& vec) {
//  setTranslation(getTranslation() + vec);
//}
//
//void Mat4::rotX(const float& angle) {
//  multiply(Mat4(1, 0,           0,          0,
//                0, cos(angle), -sin(angle), 0,
//                0, sin(angle),  cos(angle), 0,
//                0, 0,           0,          1));
//}
//
//void Mat4::rotY(const float& angle) {
//  multiply(Mat4(cos(angle), 0, sin(angle), 0,
//                0,          1, 0,          0,
//               -sin(angle), 0, cos(angle), 0,
//                0,          0, 0,          1));
//}
//
//void Mat4::rotZ(const float& angle) {
//  multiply(Mat4(cos(angle), -sin(angle), 0, 0,
//                sin(angle),  cos(angle), 0, 0,
//                0,           0,          1, 0,
//                0,           0,          0, 1));
//}
//
//
//Vec3 Mat4::getTranslation() const {
//  return Vec3(m[3], m[7], m[11]);
//}
//
//Vec3 Mat4::getScale() const {
//  return Vec3(m[0], m[5], m[10]);
//}
//
//Quat Mat4::getOrientation() const {
//  // TODO
//  return Quat(0,0,0,1);
//}

void Mat4::multiply(const Mat4& other) {
  *this = other * (*this);
}

Mat4 Mat4::operator*(const Mat4& rhs) const {
  Mat4 res(0.0); // zero matrix

  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      for (int i = 0; i < SIZE; i++) {
        res.m[(row * SIZE) + col] += m[(row * SIZE) + i] * rhs.m[(i * SIZE) + col];
      }
    }
  }
  return res;
}

Vec4 Mat4::operator*(const Vec4& rhs) const {
  Vec4 res(0.0); // zero vector

  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
        res[row] += m[(row * SIZE) + col] * rhs[row];
    }
  }
  return res;
}

bool Mat4::operator==(const Mat4& rhs) {
  for (int i = 0; i < 16; i++) {
    if (m[i] != rhs.m[i]) {
      return false;
    }
  }
  return true;
}

void Mat4::print() const {
  std::string output = "{ " + to_str(m[0])  + ", " + to_str(m[1])  + ", " + to_str(m[2])  + ", " + to_str(m[3])  + ",\n" +
                       "  " + to_str(m[4])  + ", " + to_str(m[5])  + ", " + to_str(m[6])  + ", " + to_str(m[7])  + ",\n" +
                       "  " + to_str(m[8])  + ", " + to_str(m[9])  + ", " + to_str(m[10]) + ", " + to_str(m[11]) + ",\n" +
                       "  " + to_str(m[12]) + ", " + to_str(m[13]) + ", " + to_str(m[14]) + ", " + to_str(m[15]) + " }\n";
  log(output);
}

} // namespace linalg
