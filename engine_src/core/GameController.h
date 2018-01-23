#pragma once

#include "world/GameObject.h"
#include "components/camera/Camera.h"
#include <vector>

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

  void addGameObject(const GameObject& objectPrototype);
  void removeGameObject(const GameObject& gameObject);

  void addCamera(const Camera& camera);
  void removeCamera(const Camera& camera);

  std::vector<GameObject> getObjects();
  
private:
  std::vector<GameObject> objects;
  std::vector<Camera> cameras;

  bool gamePaused = false; // becomes true when menu is open etc.
  bool loading = false;	// true when game assets is loading to prevent screen tearing etc.
};