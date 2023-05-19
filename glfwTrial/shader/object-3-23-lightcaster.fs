#version 330 core

// Phone Model
struct Material {
	
	sampler2D diffuse;
	sampler2D specular;
	
	float shininess;
};


struct Light {

	//vec3 pos;
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 normal;
in vec3 fragpos;
in vec2 tex;

uniform vec3 viewpos;

uniform Material material;
uniform Light light;

out vec4 FragColor;

void main() {
	
	// ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse,tex));
	
	//diffuse
	vec3 norm = normalize(normal);
	vec3 lightdir = normalize(-light.direction);
	float diff = max(dot(lightdir,norm),0.0);
	vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse,tex));
	
	// specular
	vec3 viewdir = normalize(viewpos - fragpos);
	vec3 reflectdir = reflect(-lightdir, norm);
	float spec = pow(max(dot(reflectdir,viewdir),0.0),material.shininess);
	vec3 specular = spec * light.specular * (vec3(texture(material.specular,tex)));
	
	vec3 rst = ambient + diffuse + specular;
	FragColor = vec4(rst,1.0f);
}