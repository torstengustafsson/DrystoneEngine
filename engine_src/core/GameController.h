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

  void addGameObject(std::shared_ptr<GameObject> o);
  void removeGameObject(std::shared_ptr<GameObject> o);

  std::vector<std::shared_ptr<GameObject>> getObjects();
  
private:
  std::vector<std::shared_ptr<GameObject>> objectList;

  bool gamePaused = false; // becomes true when menu is open etc.
  bool loading = false;	// true when game assets is loading to prevent screen tearing etc.
};