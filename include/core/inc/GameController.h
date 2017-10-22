#pragma once

#include <vector>
#include <memory>
#include "InputHandler.h"
#include "world/inc/GameObject.h"
#include "world/inc/Player.h"

/*
* TODO: write description
*/

class GameController {
friend class InputHandler;
public:
  GameController(std::shared_ptr<Player> _player);
	
  void frame();
  bool isPaused();
  bool isLoading();

  std::vector<GameObject*> getObjects();
  
private:
  std::vector<GameObject*> objectList;

  bool gamePaused = false; // becomes true when menu is open etc.
  bool loading = false;	// true when game assets is loading to prevent screen tearing etc.
	
  std::shared_ptr<Player> player;
};