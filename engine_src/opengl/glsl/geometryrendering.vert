#version 440

in vec4 vPosition;
in vec4 vColor;

out vec4 color;

uniform mat4 MVP;

void main(void) {
    color = vColor;
    gl_Position =  MVP * vPosition;
}