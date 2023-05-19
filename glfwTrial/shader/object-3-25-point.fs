#version 330 core

in vec3 fragpos;
in vec3 normal;
in vec2 tex;

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	
	float shininess;
};

struct Light {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	vec3 pos;
	vec3 direction;
	float cutoff;
	float outercutoff;
	
	float constant;
	float linear;
	float quadratic;
};

uniform Material material;
uniform Light light;
uniform vec3 viewpos;

out vec4 FragColor;

void main() {

	float distance = length(light.pos - fragpos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	vec3 ambient = light.ambient * vec3(texture(material.diffuse,tex));
	
	vec3 norm = normalize(normal);
	
	//diffuse
	vec3 lightdir = normalize(light.pos - fragpos);
	float diff = max(dot(lightdir,norm),0.0);
	vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse,tex));
	
	// specular
	vec3 viewdir = normalize(viewpos - fragpos);
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec = pow(max(dot(reflectdir,viewdir),0.0),material.shininess);
	vec3 specular = spec * light.specular * vec3(texture(material.specular,tex));
	
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	float theta = dot(normalize(-light.direction),lightdir);
	float epsilon = light.cutoff - light.outercutoff;
	float intensity = clamp((theta-light.outercutoff)/epsilon,0.0,1.0);
	
	diffuse *= intensity;
	specular *= intensity;
	
	
	vec3 rst = ambient + diffuse + specular;
	FragColor = vec4(rst,1.0);	
}