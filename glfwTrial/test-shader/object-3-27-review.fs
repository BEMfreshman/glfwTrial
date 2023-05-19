#version 330 core

in vec3 normal;
in vec3 fragpos;
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
	
	float kc;
	float kl;
	float kq;
};

uniform Material material;
uniform Light light;
uniform vec3 viewpos;

out vec4 FragColor;

void main() {
	
	vec3 ambient = light.ambient * texture(material.diffuse,tex).rgb;
	
	vec3 norm = normalize(normal);
	vec3 lightdir = normalize(light.pos - fragpos);
	float diff = max(dot(lightdir,norm),0.0);
	vec3 diffuse = diff * light.diffuse * texture(material.diffuse,tex).rgb;
	
	vec3 viewdir = normalize(viewpos - fragpos);
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec = pow(max(dot(reflectdir,viewdir),0.0),material.shininess);
	vec3 specular = spec * light.specular * texture(material.specular,tex).rgb;
	
	float dis = length(light.pos - fragpos);
	
	float attenuation = 1.0/(light.kc + light.kl * dis + light.kq * dis * dis);
	
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	vec3 rst = ambient + diffuse + specular;
	FragColor = vec4(rst,1.0);
	
}
