#pragma once

#include <string>
#include <memory>
#include <components/geometries/inc/Mesh.h>

/*
* TODO: write description
*/

class GameObject {
public:
  GameObject(std::shared_ptr<Mesh> _mesh = nullptr);

  void render();

  int getCameraX();
  int getCameraY();
  int getWorldX();
  int getWorldY();

protected:
  // the name that will be displayed during player interaction etc.
  std::string name;

  // components
  std::shared_ptr<Mesh> mesh;

  // positions in world coordinates and camera coordinates
  int xPosCamera;
  int yPosCamera;
  int xPosWorld;
  int yPosWorld;
};
