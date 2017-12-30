#pragma once

#include "linalg/Vec3.h"
#include "world/GameObject.h"
#include "components/EventHandler.h"

#include <memory>

class PlaneHandler : public EventHandler {
public:
  PlaneHandler(const float& incr);

  void update() override;

private:
  float animationVal;
  float animationIncr;
};
