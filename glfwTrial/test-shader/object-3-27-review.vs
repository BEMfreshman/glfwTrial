#version 330 core

layout(location = 0) in vec3 apos;
layout(location = 1) in vec3 anormal;
layout(location = 2) in vec2 atex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 normal;
out vec3 fragpos;
out vec2 tex;

void main() {
	gl_Position = proj *  view * model * vec4(apos,1.0);
	
	normal = mat3(transpose(inverse(model))) * anormal;
	fragpos = vec3(model * vec4(apos,1.0));
	tex = atex;
}