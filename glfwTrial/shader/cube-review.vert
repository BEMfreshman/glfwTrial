#version 330 core

layout(location = 0) in vec3 apos;
layout(location = 1) in vec2 atex;

out vec2 texcoord;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main() {
    gl_Position = proj * view * model * vec4(apos,1.0);
    texcoord = atex;
}