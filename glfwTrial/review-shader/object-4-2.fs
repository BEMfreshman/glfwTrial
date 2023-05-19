#version 330 core

in vec3 fragpos;
in vec3 normal;
in vec2 tex;

out vec3 fragcolor;

struct Material {
	
	sampler2D diffuse;
	sampler2D specular;
	
	float shininess;
};

struct DirLight {
	
	vec3 dir;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight {
	
	vec3 pos;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	float kc;
	float kl;
	float kq;
};

#define NR_POINT_LIGHTS 4

uniform vec3 viewpos;
uniform PointLight pointlight[NR_POINT_LIGHTS];
uniform DirLight dirlight;
uniform Material material;

vec3 CalcDirLight();
vec3 CalcPointLight();


void main() {
	vec3 norm = normalize(normal);
	vec3 viewdir = normalize(viewpos - fragpos);
	
	vec3 rst = CalcDirLight(dirlight,norm,viewdir);
	
	for (int i = 0; i < NR_POINT_LIGHTS; i++ ) {
		rst += CalcPointLight(pointlight[i],norm,fragpos,viewdir);
	}
	
	fragcolor = vec4(rst,1.0);
}


vec3 CalcDirLight(DirLight light, vec3 norm, vec3 viewdir) {
	
	vec3 lightdir =normalize(-light.dir);
	
	float diff = max(dot(lightdir,norm),0.0);
	
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec = pow(max(dot(reflectdir,viewdir),0.0),material.shininess);

	vec3 ambient  = light.ambient * texture(material.diffuse,tex).rgb;
	vec3 diffuse  = diff * light.diffuse * texture(material.diffuse,tex).rgb;
	vec3 specular = spec * light.specular * texture(material.specular,tex).rgb;
	

	return (ambient + diffuse + specular);

}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewdir) {
	float dis = length(light.pos - fragpos);
	float attenuation = 1.0 / (light.kc + light.kl * dis + light.kq * dis * dis);
	
	vec3 lightdir = light.pos - fragpos;
	float diff = max(dot(lightdir,norm),0.0);
	
	vec3 reflectdir = reflect(-lightdir,norm);
	float spec = pow(max(dot(reflectdir,viewdir),0.0),material.shininess);
	
	vec3 ambient  = light.ambient * texture(material.diffuse,tex).rgb;
	vec3 diffuse  = diff * light.diffuse * texture(material.diffuse,tex).rgb;
	vec3 specular = spec * light.specular * texture(material.specular,tex).rgb;
	
	
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	return (ambient + diffuse + specular);
}