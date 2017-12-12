#pragma once

#include <vector>
#include "GL/glew.h"

/*
* Handlers shader programs. Not yet implemented.
*/

// TODO: Manager for shaders used by the game engine
class ShaderManager {
public:
  ShaderManager();

  bool loadShader(const std::string &fileName, GLenum shaderType);
  bool linkShaders();

private:

  std::vector<int> shaderIds;
};
