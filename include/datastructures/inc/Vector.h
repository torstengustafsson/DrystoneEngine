#pragma once

#include <initializer_list>

/*
* TODO: write description
*/

class Vec2 {
public:
  Vec2(float x = 0.0f, float y = 0.0f);

  std::initializer_list<float> operator()();

  float x;
  float y;
};

class Vec3 : public Vec2 {
public:
  Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

  std::initializer_list<float> operator()();

  float z;
};

class Vec4 : public Vec3 {
public:
  Vec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);

  std::initializer_list<float> operator()();

  float w;
};
