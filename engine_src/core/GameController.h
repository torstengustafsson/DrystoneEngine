#pragma once

#include "world/GameObject.h"

#include <vector>
#include <memory>

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

  void addGameObject(const GameObject& o);
  void removeGameObject(const GameObject& o);

  std::vector<GameObject> getObjects();
  
private:
  // This object list should not be used for performance heavy tasks
  std::vector<GameObject> objectList;

  bool gamePaused = false; // becomes true when menu is open etc.
  bool loading = false;	// true when game assets is loading to prevent screen tearing etc.
};