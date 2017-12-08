#version 120

// some drivers requires this to function properly
precision highp float;

in vec4 ex_Color;

void main(void) {
    //gl_FragColor = vec4(ex_Color);
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}