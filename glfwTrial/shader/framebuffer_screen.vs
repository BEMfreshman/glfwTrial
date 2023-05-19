#version 330 core
layout(location = 0) in vec2 apos;
layout(location = 1) in vec2 atex;

out vec2 texcoord;

void main() {
	texcoord = atex;
	gl_Position = vec4(apos.x, apos.y,0.0,1.0);
}