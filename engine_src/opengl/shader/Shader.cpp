
#include "opengl/shader/Shader.h"
#include "core/inc/Log.h"

#include <sstream>
#include <fstream>

Shader::Shader(std::string vs, std::string fs, std::string gs)
  : vertexShader(vs),
    fragmentShader(fs),
    geometryShader(gs) {

  shaderProgram = glCreateProgram();
  
  if (!recompile()) {
    log("\nshader error (could not recompile)!\n");
  }
}

Shader::~Shader() {
  cleanUp();
}

bool Shader::recompile() {

  if (!loadShader(vertexShader, GL_VERTEX_SHADER)) {
    return false;
  }

  if (!loadShader(fragmentShader, GL_FRAGMENT_SHADER)) {
    return false;
  }

//  if (!loadShader(geometryShader, GL_GEOMETRY_SHADER)) {
//    return false;
//  }

  if (!linkShaders()) {
    return false;
  }

  return true;
}

std::string Shader::readFile(const char* fileName) {
    // Open file
    std::ifstream ifs(fileName);

    // Read file into buffer
    std::stringstream buffer;
    buffer << ifs.rdbuf();

    // Make a std::string and fill it with the contents of buffer
    std::string fileContent = buffer.str();

    return fileContent;
}

// Tries to compile the shader. Returns false if something fails
bool Shader::compileShader(int shaderId) {
  
  glCompileShader(shaderId);

  // Ask OpenGL if the shaders was compiled
  int wasCompiled = 0;
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &wasCompiled);

  if(!wasCompiled) {
    printShaderCompilationErrorInfo(shaderId);
  }

  // Return false if compilation failed
  return (wasCompiled != 0);
}

int Shader::createShader(const std::string &fileName, GLenum shaderType) {
  // Read file as std::string 
  std::string str = readFile(fileName.c_str());

  // c_str() gives us a const char*, but we need a non-const one
  char* src = const_cast<char*>(str.c_str());
  int32_t size = str.length();

  // Create an empty vertex shader handle
  int shaderId = glCreateShader(shaderType);

  // Send the vertex shader source code to OpenGL
  glShaderSource(shaderId, 1, &src, &size);

  return shaderId;
}

bool Shader::loadShader( const std::string &fileName, GLenum shaderType) {

  int shaderId = createShader(fileName, shaderType);

  if (compileShader(shaderId)) {
    glAttachShader(shaderProgram, shaderId);
    shaderIds.push_back(shaderId);
    return true;
  }

  log("error loading shader id: " + std::to_string(shaderId));
  return false;
}

bool Shader::linkShaders() {
  // Link. At this point, our shaders will be inspected/optized and the binary code generated
  // The binary code will then be uploaded to the GPU
  glLinkProgram(shaderProgram);

  // Verify that the linking succeeded
  int isLinked;
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, (int *)&isLinked);

  if (isLinked == false) {
    printShaderLinkingError(shaderProgram);
  }

  return isLinked != 0;
}

// load the shader into the rendering pipeline
void Shader::useProgram() {
  glUseProgram(shaderProgram);
}

void Shader::cleanUp() {
  glUseProgram(0);

  for (auto i : shaderIds) {
    glDetachShader(shaderProgram, i);
  }

  glDeleteProgram(shaderProgram);

  for (auto i : shaderIds) {
    glDeleteShader(i);
  }
}

void Shader::printShaderLinkingError(int32_t shaderId)
{
  log("=======================================\n");
  log("Shader linking failed : ");

  // Find length of shader info log
  int maxLength;
  glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

  log("Info Length : " + std::to_string(maxLength));

  // Get shader info log
  char* shaderProgramInfoLog = new char[maxLength];
  glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, shaderProgramInfoLog);

  log("Linker error message : " + std::string(shaderProgramInfoLog));

  /* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
  /* In this simple program, we'll just leave */
  delete shaderProgramInfoLog;
  return;
}

// If something went wrong whil compiling the shaders, we'll use this function to find the error
void Shader::printShaderCompilationErrorInfo(int32_t shaderId)
{

  // Find length of shader info log
  int maxLength;
  glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

  // Get shader info log
  char* shaderInfoLog = new char[maxLength];
  glGetShaderInfoLog(shaderId, maxLength, &maxLength, shaderInfoLog);

  std::string log = shaderInfoLog;

  if (log.length()) {
    log("=======================================\n");
    log("Error on shader id: " + std::to_string(shaderId));
    log(std::string(shaderInfoLog));
    log("=======================================\n");
  }
  // Print shader info log
  delete shaderInfoLog;
}
