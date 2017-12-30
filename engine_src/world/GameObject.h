#pragma once

#include "linalg/Mat4.h"
#include "core/util/UuidGenerator.h"

#include <string>
#include <vector>
#include <memory>

/*
* The basic object that all ingame objects are made up of. 
* Based on the component pattern.
* TODO: Each GameObject may have other GameObjects as its children.
*/

// forward declarations
namespace linalg {
  class Vec3;
}
class Mesh;
class EventHandler;

// GameObject instances with index set to GO_PROTOTYPE will manage themselves. 
// anything else is managed by ComponentManager.
#define GO_PROTOTYPE -1

class GameObject {
public:
  GameObject(const int& _index, Mesh* _mesh = nullptr);
  ~GameObject();

  Mesh* getMesh() const;

  void setPosition(const linalg::Vec3& pos);

  void addEventHandler(std::shared_ptr<EventHandler>);
  
  const int getIndex() const;
  const std::vector<std::shared_ptr<EventHandler>>& getEventHandlers() const;

  void runEventHandlers();

  //void addChild(const GameObject& child);

  friend class ComponentManager;

  bool operator==(const GameObject& rhs);
  GameObject& operator=(const GameObject& rhs);

private:
  std::string name;

  // used to reference components. 
  // based on index in componentmanager array.
  const int index;

  // references to components are stored here. The actual component objects are 
  // managed by the ComponentManager class.
  // EventHandlers are the exception, as they are managed directly by the GameObject class.
  // raw pointers are used for performance-heavy tasks (main loop).
  Mesh* mesh;

  // TODO: event handlers are currently only accessed by pointers (bad performance) Fix if possible.
  std::vector<std::shared_ptr<EventHandler>> eventHandlers;

  //std::vector<GameObject> children;
};
