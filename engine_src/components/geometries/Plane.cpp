#include "components/geometries/Plane.h"
#include "core/inc/Globals.h"
#include "opengl/shader/Shader.h"

Plane::Plane() 
  : Plane(1.0f, 1.0f) {
}

Plane::Plane(float _width, float _height) 
  : width(_width),
    height(_height) {
}

void Plane::render(const linalg::Mat4& M, const linalg::Mat4& V, const linalg::Mat4& P) {

  linalg::Vec3 pos = M.getTranslation();

  // tutorial
  const uint32_t points = 6;
  const uint32_t floatsPerPoint = 3;
  const uint32_t floatsPerColor = 4;

  //const GLfloat square[points][floatsPerPoint] = {
  //  { -width,  height,  0.5 }, // triangle 1
  //  {  width,  height,  0.5 },
  //  {  width, -height,  0.5 },

  //  { -width,  height,  0.5 }, // triangle 2
  //  {  width, -height,  0.5 },
  //  { -width, -height,  0.5 },
  //};

  const GLfloat square[points][floatsPerPoint] = {
    { pos.x - width, pos.y + height,  0.5 }, // triangle 1
    { pos.x + width, pos.y + height,  0.5 },
    { pos.x + width, pos.y - height,  0.5 },

    { pos.x - width, pos.y + height,  0.5 }, // triangle 2
    { pos.x + width, pos.y - height,  0.5 },
    { pos.x - width, pos.y - height,  0.5 },
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
