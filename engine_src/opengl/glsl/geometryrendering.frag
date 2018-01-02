#version 120

// apparently some drivers requires this to function properly
precision highp float;

in vec4 color;

void main(void) {

    gl_FragColor = color; // hardcoded color based on vertex position
}
