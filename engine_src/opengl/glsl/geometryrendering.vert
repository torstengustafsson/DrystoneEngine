#version 440

in vec4 vPosition;
in vec4 vColor;

out vec4 color;

uniform mat4 MVP;

void main(void) {
	vec4 test = MVP * vPosition;
	test.w = 1.0;
    color = (vec4(1.0) + test) / 2.0;
    gl_Position =  test;
}
