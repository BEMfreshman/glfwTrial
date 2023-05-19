#version 330 core

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	float shininess;
};

struct Light {

	vec3 pos;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform Light    light;

uniform vec3 viewpos;

in vec3 frag;
in vec3 normal;

out vec4 FragColor;

void main() {
	
	vec3 ambient = light.ambient * material.ambient;
	
	vec3 norm = normalize(normal);
	vec3 lightdir =  normalize(light.pos - frag);
	float diff = max(dot(lightdir,norm),0.0);
	vec3 diffuse = diff * light.diffuse * material.diffuse;
	
	vec3 viewdir = normalize(viewpos - frag);
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec = pow(max(dot(reflectdir, viewdir),0.0),material.shininess);
	vec3 specular = spec * light.specular * material.specular;
	
	vec3 rst = ambient + diffuse + specular;
	FragColor = vec4(rst,1.0f);
	
}