#include "datastructures/geometries/Plane.h"
#include "core/inc/Globals.h"
#include "opengl/shader/Shader.h"
#include "GL/glew.h"
#include "SDL.h"

Plane::Plane() 
  : Plane(linalg::Vec3(0.0f, 0.0f, 0.0f), 1.0f, 1.0f) {
}

Plane::Plane(linalg::Vec3 pos, float _width, float _height) 
  : width(_width),
    height(_height) {

  transform.setTranslation(pos);
}

void Plane::render() {

  // tutorial
  const uint32_t points = 6;
  const uint32_t floatsPerPoint = 3;
  const uint32_t floatsPerColor = 4;

  const GLfloat square[points][floatsPerPoint] = {
    { -0.5,  0.5,  0.5 }, // triangle 1
    {  0.5,  0.5,  0.5 },
    {  0.5, -0.5,  0.5 }, 

    { -0.5,  0.5,  0.5 }, // triangle 2
    { 0.5, -0.5,  0.5 },
    { -0.5, -0.5,  0.5 },
  };

  const GLfloat colors[points][floatsPerColor] = {
    { 0.0, 1.0, 0.0, 1.0 }, // triangle 1
    { 1.0, 1.0, 0.0, 1.0 },
    { 1.0, 0.0, 0.0, 1.0 },
 
    { 0.0, 0.0, 1.0, 1.0 }, // triangle 2
    { 1.0, 0.0, 0.0, 1.0 },
    { 0.0, 0.0, 1.0, 1.0 },
  };

  // The positons of the position and color data within the VAO
  const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;

  // create buffer
  GLuint vbo[2], vao[1];

  Shader shader(Globals::PATH + "engine_src/opengl/glsl/geometryrendering.vert", 
                Globals::PATH + "engine_src/opengl/glsl/geometryrendering.frag");

  // Generate and assign two Vertex Buffer Objects to our handle
  glGenBuffers(2, vbo);

  // Generate and assign a Vertex Array Object to our handle
  glGenVertexArrays(1, vao);

  // Bind our Vertex Array Object as the current used object
  glBindVertexArray(vao[0]);

  // Positions
  // ===================
  // Bind our first VBO as being the active buffer and storing vertex attributes (coordinates)
  glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

  // Copy the vertex data from square to our buffer
  glBufferData(GL_ARRAY_BUFFER, (points * floatsPerPoint) * sizeof(GLfloat), square, GL_STATIC_DRAW);

  // Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
  glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

  // Enable our attribute within the current VAO
  glEnableVertexAttribArray(positionAttributeIndex);

  // Colors
  // =======================
  glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

  // Copy the vertex data from diamond to our buffer
  glBufferData(GL_ARRAY_BUFFER, (points * floatsPerColor) * sizeof(GLfloat), colors, GL_STATIC_DRAW);

  // Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
  glVertexAttribPointer(colorAttributeIndex, 4, GL_FLOAT, GL_FALSE, 0, 0);

  // Note : We didn't enable the colors here!

  // Set up shader ( will be covered in the next part )
  // ===================
  shader.useProgram();

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glDrawArrays(GL_TRIANGLES, 0, 6);
}
