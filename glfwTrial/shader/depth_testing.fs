#version 330 core

out vec4 FragColor;

in vec2 tex;

uniform sampler2D texture1;

void main() {
	FragColor = texture(texture1,tex);
	//FragColor = vec4(vec3(gl_FragCoord.z),1.0);
}