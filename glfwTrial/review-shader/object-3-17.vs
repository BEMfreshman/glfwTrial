#version 330 core

layout(location = 0) in vec3 apos;
layout(location = 1) in vec3 anormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 frag;
out vec3 normal;

void main() {
	
	gl_Position = proj * view * model * vec4(apos,1.0);
	normal = mat3(transpose(inverse(model))) * anormal;
	frag = vec3(model*vec4(apos,1.0));
	
}