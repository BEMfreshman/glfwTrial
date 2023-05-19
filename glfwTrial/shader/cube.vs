#version 330 core

layout(location = 0) in vec3 apos;
layout(location = 1) in vec2 atex;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

out vec2 texcoord;

void main()
{
	texcoord = atex;
	gl_Position = proj * view * model * vec4(apos,1.0);
}