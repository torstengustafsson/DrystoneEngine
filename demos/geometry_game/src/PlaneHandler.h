#pragma once

#include "linalg/Vec3.h"
#include "world/GameObject.h"
#include "components/EventHandler.h"

#include <memory>

enum class Preset {
  PRESET1,
  PRESET2
};

class PlaneHandler : public EventHandler {
public:
  PlaneHandler(std::shared_ptr<InputHandler> _inputHandler, Preset _preset);

  void update() override;

  bool active;

private:
  float animationVal;
  Preset preset;
};
