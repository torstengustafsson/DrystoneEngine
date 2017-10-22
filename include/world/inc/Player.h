#pragma once

#include <string>
#include "GameObject.h"

/*
* TODO: write description
*/

class Player : public GameObject {
public:
  Player(std::string _name);

  void render() override;

private:

};