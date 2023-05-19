#version 330 core

in vec3 texcoord;
uniform sampler3D tex;

out vec4 FragColor;

void main() {
    FragColor = tex(tex,tecoord);
}