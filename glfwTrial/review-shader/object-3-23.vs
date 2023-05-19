#version 330 core
layout(location = 0) in vec3 apos;
layout(location = 1) in vec3 anormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 normal;
out vec3 fragpos;   // pos in model view

void main() {
	
	gl_Position = proj * view * model * vec4(apos, 1.0f);
	
	normal = mat3(transpose(inverse(model))) * anormal;
	
	fragpos = vec3(model * vec4(apos,1.0f));

}

