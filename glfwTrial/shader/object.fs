#version 330 core 

in vec3 Normal;
in vec3 FragPos;

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Light {
	vec3 position;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

};

uniform Light light;
uniform Material material;

uniform vec3 lightcolor;
uniform vec3 lightpos;
uniform vec3 viewpos;

out vec4 FragColor;

void main() {
	vec3 ambient = light.ambient * material.ambient;
	
	vec3 norm = normalize(Normal);
	vec3 lightdir = normalize(lightpos - FragPos);
	float diff = max(dot(norm,lightdir),0.0);
	vec3 diffuse = light.diffuse * (diff * material.diffuse);
	
	vec3 viewdir = normalize(viewpos - FragPos);
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec= pow(max(dot(viewdir, reflectdir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * material.specular;
	
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result,1.0);
}