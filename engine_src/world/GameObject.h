#pragma once

#include <string>

/*
* TODO: write description
*/

class GameObject {
public:
  virtual ~GameObject() = default;

  virtual void render() = 0;

  int getCameraX();
  int getCameraY();
  int getWorldX();
  int getWorldY();

protected:
  // the name that will be displayed during player interaction etc.
  std::string name;

  // positions in world coordinates and camera coordinates
  int xPosCamera;
  int yPosCamera;
  int xPosWorld;
  int yPosWorld;
};
