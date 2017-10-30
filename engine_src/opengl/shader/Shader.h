#pragma once

#include <string>
#include <vector>
#include "GL/glew.h"

class Shader {
public:
  Shader(std::string vs, std::string fs = "", std::string gs = "");
  ~Shader();

  bool recompile();
  void useProgram();

private:

  std::string readFile(const char* fileName);
  int createShader(const std::string &fileName, GLenum shaderType);
  bool compileShader(int shaderId);
  bool loadShader(const std::string &fileName, GLenum shaderType);
  bool linkShaders();

  void cleanUp();

  void printShaderLinkingError(int32_t shaderId);
  void printShaderCompilationErrorInfo(int32_t shaderId);

  GLuint shaderProgram;
  std::string vertexShader;
  std::string fragmentShader;
  std::string geometryShader;

  std::vector<int> shaderIds;
};
