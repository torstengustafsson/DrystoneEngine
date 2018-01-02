#version 440

in vec4 vPosition;
in vec4 vColor;

out vec4 color;

uniform mat4 MVP;

void main(void) {
	vec4 test = MVP * vPosition;
	test = test / test.w;

	color = (vec4(1.0) + vPosition) / 2.0;
	
    gl_Position =  test;
}
