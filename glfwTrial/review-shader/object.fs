#version 330 core 

in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 lightcolor;
uniform vec3 objectcolor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main() {
	float ambientStrength = 0.3;
	float diffuseStrength = 1.0;
	float specularStrength = 0.5;
	
	vec3 ambient = ambientStrength * lightcolor;
	
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	vec3 diffuse = diffuseStrength * max(dot(lightDir,norm),0.0) * lightcolor;
	
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir,norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),32);
	vec3 specular = specularStrength * spec * lightcolor;
	
	vec3 result = (ambient + diffuse + specular) * objectcolor;
	
	FragColor =  vec4(result,1.0);
}