#include "input/inc/InputCommands.h"
#include "GL/glew.h"

ChangeBGColorCommand::ChangeBGColorCommand(vector::Vec4 _color)
  : color(_color) {

}

void ChangeBGColorCommand::execute() {
  glClearColor(color.x, color.y, color.z, color.w);
  glClear(GL_COLOR_BUFFER_BIT);
}
