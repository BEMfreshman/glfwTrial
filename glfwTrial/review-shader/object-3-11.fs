#version 330 core

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightpos;
uniform vec3 viewpos;
uniform vec3 lightcolor;
uniform vec3 objectcolor;

out vec4 FragColor;

void main() {
	float ambientStrength = 0.3;
	float diffuseStrength = 1.2;
	float specularStrength = 0.5;
	
	vec3 norm = normalize(Normal);
	
	vec3 ambient = ambientStrength * lightcolor;
	
	vec3 lightdir = normalize(lightpos - FragPos);
	vec3 diffuse = diffuseStrength * max(dot(lightdir,norm),0.0) * lightcolor;
	
	vec3 viewdir = normalize(viewpos - FragPos);
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec = pow(max(dot(viewdir,reflectdir),0.0),32);
	vec3 specular = specularStrength * spec * lightcolor;
	
	vec3 result = (ambient + diffuse + specular) * objectcolor;
	
	FragColor = vec4(result,1.0);
}