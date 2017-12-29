#include "components/Mesh.h"
#include "opengl/shader/Shader.h"
#include "core/inc/Globals.h"

Mesh::Mesh()
  : Mesh(1.0f, 1.0f) {
}

Mesh::Mesh(float _width, float _height)
  : width(_width),
    height(_height),
    square{
      { -_width,  _height,  0.5 }, // triangle 1
      {  _width,  _height,  0.5 },
      {  _width, -_height,  0.5 },

      { -_width,  _height,  0.5 }, // triangle 2
      {  _width, -_height,  0.5 },
      { -_width, -_height,  0.5 }
    } {
}

void Mesh::render(const linalg::Mat4& V, const linalg::Mat4& P) const {

  linalg::Mat4 M = transform;
  

  // The positons of the position and color data within the VAO
  const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;

  // create buffer
  GLuint vbo[2], vao[1];

  Shader shader(Globals::PATH + "engine_src/opengl/glsl/geometryrendering.vert", 
                Globals::PATH + "engine_src/opengl/glsl/geometryrendering.frag");

  // Generate and assign two Vertex Buffer Objects to our handle
  glGenBuffers(1, vbo);

  // Generate and assign a Vertex Array Object to our handle
  glGenVertexArrays(1, vao);

  // Bind our Vertex Array Object as the current used object
  glBindVertexArray(vao[0]);


  // Positions
  // ===================
  // Bind our first VBO as being the active buffer and storing vertex attributes (coordinates)
  glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

  // Copy the vertex data from square to our buffer
  glBufferData(GL_ARRAY_BUFFER, (POINTS * FLOATSPERPOINT) * sizeof(GLfloat), square, GL_STATIC_DRAW);

  // Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
  glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

  // Enable our attribute within the current VAO
  glEnableVertexAttribArray(positionAttributeIndex);

  // Set up shader ( will be covered in the next part )
  // ===================
  shader.useProgram();
  shader.setUniform("MVP", M /* *V*P */);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glDrawArrays(GL_TRIANGLES, 0, 6);
}
