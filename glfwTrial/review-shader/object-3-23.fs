#version 330 core

// Phone Model
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

in vec3 normal;
in vec3 fragpos;

uniform vec3 viewpos;

uniform Material material;
uniform Light light;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec4 FragColor;

void main() {
	
	// ambient
	vec3 ambient = light.ambient * material.ambient;
	
	//diffuse
	vec3 norm = normalize(normal);
	vec3 lightdir = normalize(light.pos - fragpos);
	float diff = max(dot(lightdir,norm),0.0);
	vec3 diffuse = diff * light.diffuse * material.diffuse;
	
	// specular
	vec3 viewdir = normalize(viewpos - fragpos);
	vec3 reflectdir = reflect(-lightdir, norm);
	float spec = pow(max(dot(reflectdir,viewdir),0.0),material.shininess);
	vec3 specular = spec * light.specular * material.specular;
	
	vec3 rst = ambient + diffuse + specular;
	FragColor = vec4(rst,1.0f);
}