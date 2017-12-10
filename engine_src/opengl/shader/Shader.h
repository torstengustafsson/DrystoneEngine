#pragma once

#include "linalg/linalg.h"

#include <string>
#include <vector>
#include <unordered_map>
#include "GL/glew.h"

/*
* Handles a single OpenGL shader program.
*  - Each shader program may have a vertex shader and a fragment shader.
*  - Geometry and tesselation shaders may be added in the future.
*/

class Shader {
public:
  Shader(std::string vs, std::string fs = "", std::string gs = "");
  ~Shader();

  bool compile();
  void useProgram();

  void setUniform(const std::string& name, const linalg::Mat4& value);

private:

  std::string readFile(const char* fileName);
  int createShaderObject(const std::string &fileName, GLenum shaderType);
  bool compileAndAttachShader(int shaderId);
  bool linkShaders();

  GLint findUniformLocation(const std::string &name) const;

  void printShaderLinkingError(int32_t shaderId);
  void printShaderCompilationErrorInfo(int32_t shaderId);

  GLuint shaderProgram;
  std::string vertexShader;
  std::string fragmentShader;
  std::string geometryShader;

  // Uniform location cache. Clear after linking.
  mutable std::unordered_map<std::string, GLint> uniformLookups;

  // Id:s to vertex shader, fragment shader etc.
  std::vector<int> shaderIds;
};
