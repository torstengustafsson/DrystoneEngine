#version 120

// apparently some drivers requires this to function properly
precision highp float;

in vec4 color;

void main(void) {
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); // hardcoded red color
}