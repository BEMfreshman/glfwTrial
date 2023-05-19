#version 330 core

layout(location = 0) in vec3 apos;

uniform mat4 proj;
uniform mat4 view;

out vec3 texcoord;

void main() {
	texcoord = apos;
	gl_Position = proj * view * vec4(apos,1.0);
}