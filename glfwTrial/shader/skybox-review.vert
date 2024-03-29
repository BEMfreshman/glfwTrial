#version 330 core

layout(location = 0) in vec3 apos;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

out vec3 texcoord;

void main() {
    gl_Position = proj * view * model * vec4(apos,1.0);
    texcoord = apos;
}