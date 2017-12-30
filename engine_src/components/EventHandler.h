#pragma once

/*
* Each event handler implementation may override these methods:
* init() - called at object creation.
* update() - called every frame.
* destroy() - called at object destruction.
*/

class EventHandler {
public:
  
  virtual ~EventHandler() = default;

  virtual void init() {}
  virtual void update() {};
  virtual void destroy() {}

  friend class GameObject;

protected:
  std::shared_ptr<GameObject> gameObject;
};
