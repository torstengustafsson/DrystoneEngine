#pragma once

#include <vector>
#include <memory>
#include "world/GameObject.h"

/*
* TODO: write description
*/

class GameController {
friend class InputHandler;
public:
  GameController();
	
  void frame();
  bool isPaused();
  bool isLoading();

  std::vector<GameObject*> getObjects();
  
private:
  std::vector<GameObject*> objectList;

  bool gamePaused = false; // becomes true when menu is open etc.
  bool loading = false;	// true when game assets is loading to prevent screen tearing etc.
};