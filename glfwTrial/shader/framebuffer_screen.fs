#version 330 core
out vec4 FragColor;

in vec2 texcoord;

uniform sampler2D screenTexture;

void main() {
	// vec3 col = texture(screenTexture, texcoord).rgb;
	// vec3 col = vec3(1.0-texture(screenTexture, texcoord));

	FragColor = texture(screenTexture,texcoord);
	float average = (FragColor.r + FragColor.g + FragColor.b)/3.0;
	FragColor = vec4(average,average,average,1.0);
	
	
	// FragColor = vec4(col,1.0);
}