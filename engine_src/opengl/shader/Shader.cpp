#include "opengl/shader/Shader.h"
#include "linalg/Mat4.h"
#include "core/inc/Log.h"

#include <sstream>
#include <fstream>

Shader::Shader(std::string vs, std::string fs, std::string gs)
  : vertexShader(vs),
    fragmentShader(fs),
    geometryShader(gs) {
  
  shaderProgram = glCreateProgram();

  if (!compile()) {
    log("\nshader error (could not compile)!\n");
  }
}

Shader::~Shader() {
  glUseProgram(0);
  glDeleteShader(shaderProgram);
}

bool Shader::compile() {

  // Create shader objects
  int shaderVert = createShaderObject(vertexShader, GL_VERTEX_SHADER);
  int shaderFrag = createShaderObject(fragmentShader, GL_FRAGMENT_SHADER);
  
  if (!shaderVert || !shaderFrag) {
    log_verbose("Error: Shader object could not be created");
    return false;
  }

  // Compile individual shaders
  if (!compileAndAttachShader(shaderVert)) {
    log_verbose("Error: Vertex shader compile error");
    return false;
  }

  if (!compileAndAttachShader(shaderFrag)) {
    log_verbose("Error: Fragment shader compile error");
    return false;
  }

  // link shader program
  if (!linkShaders()) {
    log_verbose("Error: Shader linking failed");
    return false;
  }

  return true;
}

// load the shader into the rendering pipeline
void Shader::useProgram() {
  glUseProgram(shaderProgram);
}

// set a single uniform
void Shader::setUniform(const std::string& name, const linalg::Mat4& value) {
  GLint location = findUniformLocation(name);
  glUniformMatrix4fv(location, 1, GL_TRUE, value.m);
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
bool Shader::compileAndAttachShader(int shaderId) {
  
  glCompileShader(shaderId);

  int wasCompiled = 0;
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &wasCompiled);

  printShaderCompilationErrorInfo(shaderId);

  if (wasCompiled) {
    glAttachShader(shaderProgram, shaderId);
    shaderIds.push_back(shaderId);
  }

  return (wasCompiled != 0);
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

int Shader::createShaderObject(const std::string &fileName, GLenum shaderType) {
  // Read file as std::string 
  std::string s = readFile(fileName.c_str());

  // c_str() gives us a const char*, but we need a non-const one
  char* src = const_cast<char*>(s.c_str());
  int32_t size = s.length();

  // Create an empty vertex shader handle
  int shaderId = glCreateShader(shaderType);

  // Send the vertex shader source code to OpenGL
  glShaderSource(shaderId, 1, &src, &size);

  return shaderId;
}

GLint Shader::findUniformLocation(const std::string &name) const {
  auto it = uniformLookups.find(name);
  if (it != uniformLookups.end()) {
    return it->second;
  }
  else {
    GLint location = glGetUniformLocation(shaderProgram, name.c_str());
    uniformLookups[name] = location;

    return location;
  }
}

void Shader::printShaderLinkingError(int32_t shaderId)
{
  std::string message = "";
  message += "=======================================\n";
  message += "Shader linking failed : \n";

  // Find length of shader info log
  int maxLength;
  glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

  message += "Info Length : " + std::to_string(maxLength);

  // Get shader info log
  char* shaderProgramInfoLog = new char[maxLength];
  glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, shaderProgramInfoLog);

  message += "Linker error message : " + std::string(shaderProgramInfoLog) + "\n";

  log(message);

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

  std::string shaderLog = shaderInfoLog;

  if (shaderLog.find("warning") != std::string::npos ||
      shaderLog.find("ERROR") != std::string::npos) {
    std::string message = "";
    message += "=======================================\n";
    message += "Shader id(" + std::to_string(shaderId) + ") - ";
    message += std::string(shaderInfoLog) + "\n";
    message += "=======================================\n";
    log(message);
  }
  // Print shader info log
  delete shaderInfoLog;
}
