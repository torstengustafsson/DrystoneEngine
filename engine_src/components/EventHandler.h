#pragma once

#include <memory>

/*
* Each event handler implementation may override these methods:
* init() - called at object creation.
* update() - called every frame.
* destroy() - called at object destruction.
*
* Event handlers may have access to input. In that case, setInputHandler
* must be called before any addInputMapping calls are made.
*/

// forward declarations
class InputHandler;
class InputCommand;

class EventHandler {
public:
  
  virtual ~EventHandler() = default;

  virtual void init() {}
  virtual void update() {};
  virtual void destroy() {}

  void setInputHandler(std::shared_ptr<InputHandler> _inputHandler);
  void addInputMapping(const int key, std::shared_ptr<InputCommand> command);

  friend class GameObject;

protected:
  std::shared_ptr<GameObject> gameObject;

private:
  std::shared_ptr<InputHandler> inputHandler;
};
