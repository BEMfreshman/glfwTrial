
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "stb_image.h"

#include <iostream>

using std::cout;
using std::endl;

using std::vector;
using std::string;
//
//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		cout << "Failed to create GLFW windows" << endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		cout << "Failed to initialize GLAD" << endl;
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 600);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//
//	return 0;
//
//}

////---- reivew ---
//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(800, 600,"Review",NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 600);
//
//	while (!glfwWindowShouldClose(win)) {
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}

//const char* vtshadersrc = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
//"}\0";
//
//const char* fgshadersrc =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"uniform vec4 ourColor;\n"
//"void main(){\n"
//"FragColor = ourColor;\n"
//"}\0";
//
//int main() {
//
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(800, 600, "Triangle", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, 800, 600);
//
//	float vertices[] = {
//		0.5f, 0.5f, 0.0f,   // 右上角
//		0.5f, -0.5f, 0.0f,  // 右下角
//		-0.5f, -0.5f, 0.0f, // 左下角
//		-0.5f, 0.5f, 0.0f   // 左上角
//	};
//
//	unsigned int indices[] = {
//		0, 1, 3, // 第一个三角形
//		1, 2, 3  // 第二个三角形
//	};
//
//	unsigned int vtshader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vtshader, 1, &vtshadersrc, NULL);
//	glCompileShader(vtshader);
//
//	int success;
//	char infoMsg[512];
//	glGetShaderiv(vtshader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vtshader, 512, NULL, infoMsg);
//		cout << "Failed in vtshader with msg : " << endl;
//		cout << infoMsg << endl;
//	}
//
//	unsigned int fgshader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fgshader, 1, &fgshadersrc, NULL);
//	glCompileShader(fgshader);
//
//	glGetShaderiv(fgshader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fgshader, 512, NULL, infoMsg);
//		cout << "Failed in fgshader with msg : " << endl;
//		cout << infoMsg << endl;
//	}
//
//	unsigned int prog = glCreateProgram();
//	glAttachShader(prog, vtshader);
//	glAttachShader(prog, fgshader);
//	glLinkProgram(prog);
//
//	glGetProgramiv(prog, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(prog, 512, NULL, infoMsg);
//		cout << "Failed in program with msg : " << endl;
//		cout << infoMsg << endl;
//	}
//
//	glDeleteShader(vtshader);
//	glDeleteShader(fgshader);
//
//	unsigned int vao, vbo, ebo;
//	glGenVertexArrays(1, &vao);
//	glGenBuffers(1, &vbo);
//	glGenBuffers(1, &ebo);
//
//	// vao vbo bind
//	glBindVertexArray(vao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//	
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// layout
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
//	glEnableVertexAttribArray(0);
//
//	// unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(win)) {
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		float timevalue = glfwGetTime();
//		float greenvalue = (sin(timevalue) / 2.0f) + 0.5f;
//		int vertexcolorloacation = glGetUniformLocation(prog, "ourColor");
//
//		glUseProgram(prog);
//		glUniform4f(vertexcolorloacation, 0.0f, greenvalue, 0.0f, 1.0f);
//
//		/*glBindVertexArray(vao);
//		glDrawArrays(GL_TRIANGLES, 0, 3);*/
//
//		glBindVertexArray(vao);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	
//	glDeleteVertexArrays(1, &vao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteBuffers(1, &ebo);
//
//	glDeleteProgram(prog);
//	glfwTerminate();
//	return 0;
//}


//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(800, 600, "Review-texture", NULL, NULL);
//
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, 800, 600);
//
//	Shader shader("shader.vs", "shader.fs");
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//	float vertices[] = {
//		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
//		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.5f, 2.5f, // top right
//		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.5f, 0.0f, // bottom right
//		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.5f  // top left 
//	};
//
//	unsigned int indices[] = {
//		0, 1, 3, // 第一个三角形
//		1, 2, 3  // 第二个三角形
//	};
//
//	unsigned int vao, vbo, ebo;
//
//	glGenVertexArrays(1, &vao);
//	glGenBuffers(1, &vbo);
//	glGenBuffers(1, &ebo);
//
//	glBindVertexArray(vao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(0));
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//
//	// texture
//	stbi_set_flip_vertically_on_load(true);
//
//	unsigned int tex1;
//	glGenTextures(1, &tex1);
//	glBindTexture(GL_TEXTURE_2D, tex1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	int width, hegith, nrChannel;
//	unsigned char* data = stbi_load("container.jpg", &width, &hegith, &nrChannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, hegith, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		cout << "Failed to load jpg file" << endl;
//		return -6;
//	}
//
//	stbi_image_free(data);
//
//	unsigned int tex2;
//	glGenTextures(1, &tex2);
//	glBindTexture(GL_TEXTURE_2D, tex2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	data = stbi_load("awesomeface.png", &width, &hegith, &nrChannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, hegith, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		cout << "Failed to load png file" << endl;
//		return -6;
//	}
//
//	stbi_image_free(data);
//
//	shader.use();
//	shader.setInt("ourTexture1", 0);
//	shader.setInt("ourTexture2", 1);
//
//	while (!glfwWindowShouldClose(win)) {
//		
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		float timevalue = glfwGetTime();
//		float mixValue = sin(timevalue);
//
//		shader.setFloat("mixValue", mixValue);
//
//		shader.use();
//		glBindVertexArray(vao);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &vao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteBuffers(1, &ebo);
//
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//
//	glfwTerminate();
//	return 0;
//}

//#define WID 800
//#define HGT 600
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//int main() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	
//	GLFWwindow* win = glfwCreateWindow(WID, HGT, "Review-texture", NULL, NULL);
//	
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//	
//	glfwMakeContextCurrent(win);
//	
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//	
//	glViewport(0, 0, WID, HGT);
//	
//	Shader shader("shader.vs", "shader.fs");
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//	float vertices[] = {
//	-5.0f, -5.0f, -5.0f,  0.0f, 0.0f,
//	 5.0f, -5.0f, -5.0f,  1.0f, 0.0f,
//	 5.0f,  5.0f, -5.0f,  1.0f, 1.0f,
//	 5.0f,  5.0f, -5.0f,  1.0f, 1.0f,
//	-5.0f,  5.0f, -5.0f,  0.0f, 1.0f,
//	-5.0f, -5.0f, -5.0f,  0.0f, 0.0f,
//
//	-5.0f, -5.0f,  5.0f,  0.0f, 0.0f,
//	 5.0f, -5.0f,  5.0f,  1.0f, 0.0f,
//	 5.0f,  5.0f,  5.0f,  1.0f, 1.0f,
//	 5.0f,  5.0f,  5.0f,  1.0f, 1.0f,
//	-5.0f,  5.0f,  5.0f,  0.0f, 1.0f,
//	-5.0f, -5.0f,  5.0f,  0.0f, 0.0f,
//
//	-5.0f,  5.0f,  5.0f,  1.0f, 0.0f,
//	-5.0f,  5.0f, -5.0f,  1.0f, 1.0f,
//	-5.0f, -5.0f, -5.0f,  0.0f, 1.0f,
//	-5.0f, -5.0f, -5.0f,  0.0f, 1.0f,
//	-5.0f, -5.0f,  5.0f,  0.0f, 0.0f,
//	-5.0f,  5.0f,  5.0f,  1.0f, 0.0f,
//
//	 5.0f,  5.0f,  5.0f,  1.0f, 0.0f,
//	 5.0f,  5.0f, -5.0f,  1.0f, 1.0f,
//	 5.0f, -5.0f, -5.0f,  0.0f, 1.0f,
//	 5.0f, -5.0f, -5.0f,  0.0f, 1.0f,
//	 5.0f, -5.0f,  5.0f,  0.0f, 0.0f,
//	 5.0f,  5.0f,  5.0f,  1.0f, 0.0f,
//
//	-5.0f, -5.0f, -5.0f,  0.0f, 1.0f,
//	 5.0f, -5.0f, -5.0f,  1.0f, 1.0f,
//	 5.0f, -5.0f,  5.0f,  1.0f, 0.0f,
//	 5.0f, -5.0f,  5.0f,  1.0f, 0.0f,
//	-5.0f, -5.0f,  5.0f,  0.0f, 0.0f,
//	-5.0f, -5.0f, -5.0f,  0.0f, 1.0f,
//
//	-5.0f,  5.0f, -5.0f,  0.0f, 1.0f,
//	 5.0f,  5.0f, -5.0f,  1.0f, 1.0f,
//	 5.0f,  5.0f,  5.0f,  1.0f, 0.0f,
//	 5.0f,  5.0f,  5.0f,  1.0f, 0.0f,
//	-5.0f,  5.0f,  5.0f,  0.0f, 0.0f,
//	-5.0f,  5.0f, -5.0f,  0.0f, 1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//	  glm::vec3(0.0f,  0.0f,  0.0f),
//	  glm::vec3(2.0f,  5.0f, -15.0f),
//	  glm::vec3(-1.5f, -2.2f, -2.5f),
//	  glm::vec3(-3.8f, -2.0f, -12.3f),
//	  glm::vec3(2.4f, -0.4f, -3.5f),
//	  glm::vec3(-1.7f,  3.0f, -7.5f),
//	  glm::vec3(1.3f, -2.0f, -2.5f),
//	  glm::vec3(1.5f,  2.0f, -2.5f),
//	  glm::vec3(1.5f,  0.2f, -1.5f),
//	  glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//	
//	//unsigned int indices[] = {
//	//	0, 1, 3, // 第一个三角形
//	//	1, 2, 3  // 第二个三角形
//	//};
//
//	unsigned int vao, vbo, ebo;
//	glGenVertexArrays(1, &vao);
//	glGenBuffers(1, &vbo);
//	//glGenBuffers(1, &ebo);
//
//	glBindVertexArray(vao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);*/
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	unsigned int tex1, tex2;
//	unsigned char* data;
//	int width, height, nrchannel;
//
//	stbi_set_flip_vertically_on_load(true);
//
//	glGenTextures(1, &tex1);
//	glGenTextures(1, &tex2);
//
//	glBindTexture(GL_TEXTURE_2D, tex1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	data = stbi_load("container.jpg", &width, &height, &nrchannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		cout << "Failed to load container jpg" << endl;
//		glfwTerminate();
//		return -4;
//	}
//	stbi_image_free(data);
//
//	glBindTexture(GL_TEXTURE_2D, tex2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	data = stbi_load("awesomeface.png", &width, &height, &nrchannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		cout << "Failed to load awesomeface png" << endl;
//		glfwTerminate();
//		return -5;
//	}
//	stbi_image_free(data);
//
//	shader.use();
//	shader.setInt("ourTexture1", 0);
//	shader.setInt("ourTexture2", 1);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		glBindVertexArray(vao);
//
//		shader.use();
//
//		for (int i = 0; i < 1; i++) {
//			glm::mat4 model = glm::mat4(1.0f);
//			glm::mat4 view = glm::mat4(1.0f);
//			glm::mat4 proj = glm::mat4(1.0f);
//
//			model = glm::translate(model, cubePositions[i]);
//
//			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
//			proj = glm::perspective(glm::radians(45.0f), (float)WID / HGT, 0.1f, 100.0f);
//
//			unsigned int modelLoc = glGetUniformLocation(shader.id, "model");
//			unsigned int viewLoc = glGetUniformLocation(shader.id, "view");
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//			shader.setMat4("proj", proj);
//
//			//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//
//	glDeleteVertexArrays(1, &vao);
//	glDeleteBuffers(1, &vbo);
//	//glDeleteBuffers(1, &ebo);
//
//	glfwTerminate();
//	return 0;
//}


//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(800, 600, "Review", NULL, NULL);
//	glfwMakeContextCurrent(win);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 600);
//
//	Shader shader("shader.vs", "shader.fs");
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -2;
//	}
//
//	float vertices[] = {
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//	  glm::vec3(0.0f,  0.0f,  0.0f),
//	  glm::vec3(2.0f,  5.0f, -15.0f),
//	  glm::vec3(-1.5f, -2.2f, -2.5f),
//	  glm::vec3(-3.8f, -2.0f, -12.3f),
//	  glm::vec3(2.4f, -0.4f, -3.5f),
//	  glm::vec3(-1.7f,  3.0f, -7.5f),
//	  glm::vec3(1.3f, -2.0f, -2.5f),
//	  glm::vec3(1.5f,  2.0f, -2.5f),
//	  glm::vec3(1.5f,  0.2f, -1.5f),
//	  glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//	
//
//	unsigned int vao, vbo;
//	glGenVertexArrays(1, &vao);
//	glGenBuffers(1, &vbo);
//	//glGenBuffers(1, &ebo);
//
//	glBindVertexArray(vao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);*/
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	unsigned int tex1, tex2;
//	unsigned char* data;
//	int width, height, nrchannel;
//
//	stbi_set_flip_vertically_on_load(true);
//
//	glGenTextures(1, &tex1);
//	glGenTextures(1, &tex2);
//
//	glBindTexture(GL_TEXTURE_2D, tex1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	data = stbi_load("container.jpg", &width, &height, &nrchannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		cout << "Failed to load container jpg" << endl;
//		glfwTerminate();
//		return -4;
//	}
//	stbi_image_free(data);
//
//	glBindTexture(GL_TEXTURE_2D, tex2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	data = stbi_load("awesomeface.png", &width, &height, &nrchannel, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		cout << "Failed to load awesomeface png" << endl;
//		glfwTerminate();
//		return -5;
//	}
//	stbi_image_free(data);
//
//	shader.use();
//	shader.setInt("ourTexture1", 0);
//	shader.setInt("ourTexture2", 1);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		glBindVertexArray(vao);
//		shader.use();
//
//		for (int i = 0; i < 10; i++) {
//			glm::mat4 model, view, proj;
//			model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//
//			view = glm::mat4(1.0f);
//			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//
//			proj = glm::mat4(1.0f);
//			proj = glm::perspective(glm::radians(45.0f), (float)800 / 600, 0.1f, 100.0f);
//
//			shader.setMat4("model", model);
//			shader.setMat4("view", view);
//			shader.setMat4("proj", proj);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//	glDeleteVertexArrays(1, &vao);
//	glDeleteBuffers(1, &vbo);
//
//	glfwTerminate();
//	return 0;
//}

//void processInput();
//
//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(800, 600, "camera", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, 800, 600);
//
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//		
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	Shader shader("shader.vs", "shader.fs");
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	unsigned int vao, vbo;
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		processInput();
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//
//	glfwTerminate();
//	return 0;
//
//}
//
//void processInput() {
//
//}

#include "camera.h"

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

Camera camera;

void processInput(GLFWwindow* win);
void mousec_callback(GLFWwindow* win, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
unsigned int loadtexture(const char* path, int* ierr);

bool firstin = true;
double lastx = 0;
double lasty = 0;

float lastFrame = 0;
float deltaTime = 0;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mousec_callback(GLFWwindow* win, double xpos, double ypos) {
    if (firstin) {
        lastx = xpos;
        lasty = ypos;
        firstin = false;
        return;
    }

    double disx = xpos - lastx;
    double disy = lasty - ypos;

    lastx = xpos;
    lasty = ypos;

    camera.ProcessMouseMovement(disx, disy);
}

unsigned int loadtexture(const char* path, int* ierr) {
    *ierr = 0;

    unsigned int tex;
    glGenTextures(1, &tex);

    int width, height, nrchannel;

    unsigned char* data = stbi_load(path, &width, &height, &nrchannel, 0);
    if (data) {
        GLenum format;
        if (nrchannel == 1) {
            format = GL_RED;
        }
        else if (nrchannel == 3) {
            format = GL_RGB;
        }
        else if (nrchannel == 4) {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    }
    else {
        *ierr = 1;
        cout << "Texture failed to load at path : " << path << endl;
        stbi_image_free(data);
        return 0;
    }

    return tex;
}

unsigned int loadcubemap(vector<string> faces, int* ierr) {
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannel;
    for (unsigned int i = 0; i < faces.size(); i++) {
        unsigned char* data = stbi_load(faces[i].c_str(),
            &width, &height, &nrChannel, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else {
            *ierr = 1;
            cout << "Texture failed to load at path : " << faces[i] << endl;
            stbi_image_free(data);
            return 0;
        }
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Review-light", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("review-shader/object.vs","review-shader/object.fs");
//	Shader lightshader("review-shader/light.vs", "review-shader/light.fs");
//
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		float r = 2.0f;
//		lightPos.x = cos(glfwGetTime()) * r;
//		lightPos.y = sin(glfwGetTime()) * r;
//		lightPos.z = 1.0f;
//
//		objectshader.setVec3("lightPos", lightPos);
//		objectshader.setVec3("viewPos", camera.Position);
//		objectshader.setVec3("lightcolor", 1.0f, 1.0f, 1.0f);
//		objectshader.setVec3("objectcolor", 1.0f, 0.5f, 0.31f);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteBuffers(1, &vbo);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Review-3-11", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("review-shader/object-3-11.vs", "review-shader/object-3-11.fs");
//	Shader lightshader("review-shader/light-3-11.vs", "review-shader/light-3-11.fs");
//	
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		float r = 2.0f;
//		lightPos.x = cos(glfwGetTime()) * r;
//		lightPos.y = sin(glfwGetTime()) * r;
//		lightPos.z = 1.0f;
//
//		objectshader.setVec3("lightpos", lightPos);
//		objectshader.setVec3("viewpos", camera.Position);
//		objectshader.setVec3("lightcolor", 1.0f, 1.0f, 1.0f);
//		objectshader.setVec3("objectcolor", 1.0f, 0.5f, 0.31f);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}


//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Review-light", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("review-shader/object.vs","review-shader/object.fs");
//	Shader lightshader("review-shader/light.vs", "review-shader/light.fs");
//
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		float r = 2.0f;
//		lightPos.x = cos(glfwGetTime()) * r;
//		lightPos.y = sin(glfwGetTime()) * r;
//		lightPos.z = 1.0f;
//
//		objectshader.setVec3("lightPos", lightPos);
//		objectshader.setVec3("viewPos", camera.Position);
//		objectshader.setVec3("lightcolor", 1.0f, 1.0f, 1.0f);
//		objectshader.setVec3("objectcolor", 1.0f, 0.5f, 0.31f);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteBuffers(1, &vbo);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Material", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("shader/object.vs", "shader/object.fs");
//	Shader lightshader("shader/light.vs", "shader/light.fs");
//	
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		//float r = 2.0f;
//		//lightPos.x = cos(glfwGetTime()) * r;
//		//lightPos.y = sin(glfwGetTime()) * r;
//		//lightPos.z = 1.0f;
//
//		objectshader.setVec3("lightpos", lightPos);
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f); // 将光照调暗了一些以搭配场景
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//
//		objectshader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
//		objectshader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
//		objectshader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
//		objectshader.setFloat("material.shininess", 32.0f);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "review-3-17", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("review-shader/object-3-17.vs",
//		"review-shader/object-3-17.fs");
//	Shader lightshader("review-shader/light-3-17.vs",
//		"review-shader/light-3-17.fs");
//
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//
//	unsigned int lightvao, objectvao, vbo;
//
//	glGenVertexArrays(1, &lightvao);
//	glGenVertexArrays(1, &objectvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currFrame = glfwGetTime();
//		deltaTime = currFrame - lastFrame;
//		lastFrame = currFrame;
//
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0f);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//		objectshader.setVec3("light.pos", lightPos);
//
//		objectshader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
//		objectshader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
//		objectshader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
//		objectshader.setFloat("material.shininess", 32.0f);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteBuffers(1, &vbo);
//
//	glfwTerminate();
//	return 0;
//}


//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "3-23-review", NULL, NULL);
//
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("review-shader/object-3-23.vs", "review-shader/object-3-23.fs");
//	Shader lightshader("review-shader/light-3-23.vs", "review-shader/light-3-23.fs");
//		
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//	
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//	
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//	
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//	
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//	
//	unsigned int objectvao, lightvao, vbo;
//	
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//	
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//
//		processInput(win);
//
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0f);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//		objectshader.setVec3("light.pos", lightPos);
//
//		objectshader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
//		objectshader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
//		objectshader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
//		objectshader.setFloat("material.shininess", 32.0f);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteBuffers(1, &vbo);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "diffuse-texture", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	Shader objectshader("shader/object-3-23.vs",
//		"shader/object-3-23.fs");
//	Shader lightshader("shader/light-3-23.vs",
//		"shader/light-3-23.fs");
//		
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//		
//		
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	int ierr = 0;
//	unsigned int tex1 = loadtexture("container2.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -6;
//	}
//
//	unsigned int tex2 = loadtexture("container2_specular.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -7;
//	}
//
//	objectshader.use();
//	objectshader.setInt("material.diffuse", 0);
//	objectshader.setInt("material.specular", 1);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0f);
//
//		glBindVertexArray(objectvao);
//		objectshader.use();
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("model", model);
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//		objectshader.setVec3("light.pos", lightPos);
//
//		objectshader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
//		objectshader.setFloat("material.shininess", 64.0f);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(lightvao);
//		lightshader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//
//	glfwTerminate();
//	return 0;
//
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "lightcaster", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//
//	Shader objectshader("shader/object-3-23-lightcaster.vs",
//		"shader/object-3-23-lightcaster.fs");
//	Shader lightshader("shader/light-3-23-lightcaster.vs",
//		"shader/light-3-23-lightcaster.fs");
//			
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		 positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//	 positions all containers
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	int ierr = 0;
//	unsigned int tex1 = loadtexture("container2.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -6;
//	}
//
//	unsigned int tex2 = loadtexture("container2_specular.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -7;
//	}
//
//	objectshader.use();
//	objectshader.setInt("material.diffuse", 0);
//	objectshader.setInt("material.specular", 1);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//		objectshader.use();
//		objectshader.setVec3("light.direction", -0.2f, -1.0f, -0.3f);
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//
//		objectshader.setFloat("material.shininess", 32.0f);
//
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0f);
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		glBindVertexArray(objectvao);
//
//		for (int i = 0; i < 10; i++) {
//			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//
//			float angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//
//			objectshader.use();
//			objectshader.setMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		}
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "lightcaster-point", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//
//	/*Shader objectshader("shader/object-3-25.vs",
//		"shader/object-3-25.fs");
//	Shader lightshader("shader/light-3-25.vs",
//		"shader/light-3-25.fs");*/
//
//	Shader objectshader("test-shader/object-3-27-review.vs",
//		"test-shader/object-3-27-review.fs");
//	Shader lightshader("test-shader/light-3-27-review.vs",
//		"test-shader/light-3-27-review.fs");
//
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//	// positions all containers
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	int ierr = 0;
//	unsigned int tex1 = loadtexture("container2.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -6;
//	}
//
//	unsigned int tex2 = loadtexture("container2_specular.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -7;
//	}
//
//	objectshader.use();
//	objectshader.setInt("material.diffuse", 0);
//	objectshader.setInt("material.specular", 1);
//
//	objectshader.setFloat("light.kc", 1.0f);
//	objectshader.setFloat("light.kl", 0.09f);
//	objectshader.setFloat("light.kq", 0.032f);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//		objectshader.use();
//		objectshader.setVec3("light.pos", lightPos);
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//
//		objectshader.setFloat("material.shininess", 32.0f);
//
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0f);
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		glBindVertexArray(objectvao);
//
//		for (int i = 0; i < 10; i++) {
//			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//
//			float angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//
//			objectshader.use();
//			objectshader.setMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		}
//
//		lightshader.use();
//
//		glm::mat4 model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glBindVertexArray(lightvao);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "lightcaster-point", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//
//	Shader objectshader("shader/object-3-25-point.vs",
//		"shader/object-3-25-point.fs");
//	Shader lightshader("shader/light-3-25-point.vs",
//		"shader/light-3-25-point.fs");
//
//	bool ret = objectshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	ret = lightshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -4;
//	}
//
//	float vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//	// positions all containers
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	unsigned int objectvao, lightvao, vbo;
//
//	glGenVertexArrays(1, &objectvao);
//	glGenVertexArrays(1, &lightvao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(objectvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindVertexArray(lightvao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	int ierr = 0;
//	unsigned int tex1 = loadtexture("container2.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -6;
//	}
//
//	unsigned int tex2 = loadtexture("container2_specular.png", &ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		return -7;
//	}
//
//	objectshader.use();
//	objectshader.setInt("material.diffuse", 0);
//	objectshader.setInt("material.specular", 1);
//
//	objectshader.setFloat("light.constant", 1.0f);
//	objectshader.setFloat("light.linear", 0.09f);
//	objectshader.setFloat("light.quadratic", 0.032f);
//
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//		objectshader.use();
//		objectshader.setVec3("light.pos", camera.Position);
//		objectshader.setVec3("light.direction", camera.Front);
//		objectshader.setFloat("light.cutoff", glm::cos(glm::radians(12.5f)));
//		objectshader.setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));
//		objectshader.setVec3("viewpos", camera.Position);
//
//		objectshader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//		objectshader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//		objectshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//
//		objectshader.setFloat("material.shininess", 32.0f);
//
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 proj = glm::mat4(1.0f);
//
//		view = camera.GetViewMatrix();
//		proj = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//		objectshader.setMat4("view", view);
//		objectshader.setMat4("proj", proj);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, tex1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, tex2);
//
//		glBindVertexArray(objectvao);
//
//		for (int i = 0; i < 10; i++) {
//			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//
//			float angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//
//			objectshader.use();
//			objectshader.setMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		}
//
//		/*lightshader.use();
//
//		glm::mat4 model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//
//		lightshader.setMat4("model", model);
//		lightshader.setMat4("view", view);
//		lightshader.setMat4("proj", proj);
//
//		glBindVertexArray(lightvao);
//		glDrawArrays(GL_TRIANGLES, 0, 36);*/
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &objectvao);
//	glDeleteVertexArrays(1, &lightvao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteTextures(1, &tex1);
//	glDeleteTextures(1, &tex2);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "", NULL, NULL);
//	if (win == NULL) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//	glfwSetCursorPosCallback(win, mousec_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//	Shader shader("shader/depth_testing.vs","shader/depth_testing.fs");
//
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -2;
//	}
//
//	float vertices[] = {
//		// positions          // texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//
//	float planeVertices[] = {
//		// positions          // texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
//		 5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//
//		 5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//		 5.0f, -0.5f, -5.0f,  2.0f, 2.0f
//	};
//
//
//	unsigned int cubevao, cubevbo;
//
//	glGenVertexArrays(1, &cubevao);
//	glGenBuffers(1, &cubevbo);
//
//	glBindVertexArray(cubevao);
//	glBindBuffer(GL_ARRAY_BUFFER, cubevbo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(0));
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//
//	unsigned int planevao, planevbo;
//	glGenVertexArrays(1, &planevao);
//	glGenBuffers(1, &planevbo);
//	glBindVertexArray(planevao);
//	glBindBuffer(GL_ARRAY_BUFFER, planevbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glBindVertexArray(0);
//
//	int ierr = 0;
//	unsigned int cubetexture = loadtexture("marble.jpg",&ierr);
//	unsigned int floortexture = loadtexture("metal.png",&ierr);
//
//	shader.use();
//	shader.setInt("texture1", 0);
//
//	while (!glfwWindowShouldClose(win)) {
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		shader.use();
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		shader.setMat4("view", view);
//		shader.setMat4("proj", projection);
//
//		glBindVertexArray(cubevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubetexture);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		/*
//		* plane
//			glBindVertexArray(planevao);
//			glActiveTexture(GL_TEXTURE0);
//			glBindTexture(GL_TEXTURE_2D, floortexture);
//			shader.setMat4("model", glm::mat4(1.0f));
//			glDrawArrays(GL_TRIANGLES, 0, 6);
//			glBindVertexArray(0);
//		*/
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &cubevao);
//	glDeleteVertexArrays(1, &planevao);
//	glDeleteBuffers(1, &cubevbo);
//	glDeleteBuffers(1, &planevbo);
//
//	glfwTerminate();
//
//	return 0;
//}

//int main() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//	glfwSetCursorPosCallback(win, mousec_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//
//	glEnable(GL_STENCIL_TEST);
//	glStencilFunc(GL_NOTEQUAL, 1, 0XFF);
//	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
//
//
//	Shader shader("shader/depth_testing.vs", "shader/depth_testing.fs");
//	Shader outlineshader("shader/shadersinglecolor.vs", "shader/shadersinglecolor.fs");
//	
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -2;
//	}
//
//	ret = outlineshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//	
//	float vertices[] = {
//		// positions          // texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	float planeVertices[] = {
//		// positions          // texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
//		5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//	
//		5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//		5.0f, -0.5f, -5.0f,  2.0f, 2.0f
//	};
//
//	unsigned int cubevao, cubevbo;
//	
//	glGenVertexArrays(1, &cubevao);
//	glGenBuffers(1, &cubevbo);
//	
//	glBindVertexArray(cubevao);
//	glBindBuffer(GL_ARRAY_BUFFER, cubevbo);
//	
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(0));
//	glEnableVertexAttribArray(0);
//	
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	
//	glBindVertexArray(0);
//	
//	unsigned int planevao, planevbo;
//	glGenVertexArrays(1, &planevao);
//	glGenBuffers(1, &planevbo);
//	glBindVertexArray(planevao);
//	glBindBuffer(GL_ARRAY_BUFFER, planevbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glBindVertexArray(0);
//	
//	int ierr = 0;
//	unsigned int cubetexture = loadtexture("marble.jpg",&ierr);
//	unsigned int floortexture = loadtexture("metal.png",&ierr);
//	
//	shader.use();
//	shader.setInt("texture1", 0);
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//		// set uniform for outline shader
//		outlineshader.use();
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		outlineshader.setMat4("view", view);
//		outlineshader.setMat4("proj", projection);
//
//		shader.use();
//		shader.setMat4("view", view);
//		shader.setMat4("proj", projection);
//
//		glStencilMask(0x00);
//		//floor
//		glBindVertexArray(planevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, floortexture);
//		shader.setMat4("model", glm::mat4(1.0f));
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//		glBindVertexArray(0);
//
//
//
//		glStencilFunc(GL_ALWAYS, 1, 0xFF);
//		glStencilMask(0xFF);
//
//		glBindVertexArray(cubevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubetexture);
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		glStencilFunc(GL_NOTEQUAL, 1, 0XFF);
//		glStencilMask(0x00);
//		glDisable(GL_DEPTH_TEST);
//		float scale = 1.1;
//
//		outlineshader.use();
//		glBindVertexArray(cubevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubetexture);
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		model = glm::scale(model, glm::vec3(scale, scale, scale));
//		outlineshader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(scale, scale, scale));
//		outlineshader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		glStencilMask(0xFF);
//		glStencilFunc(GL_ALWAYS, 0, 0xFF);
//		glEnable(GL_DEPTH_TEST);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//		
//	}
//
//	glDeleteVertexArrays(1, &cubevao);
//	glDeleteVertexArrays(1, &planevao);
//	glDeleteBuffers(1, &cubevbo);
//	glDeleteBuffers(1, &planevbo);
//
//
//	glfwTerminate();
//	return 0;
//}


//int main() {
//
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
//		glfwTerminate();
//		return -2;
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	float cubeVertices[] = {
//		// positions          // texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//	float planeVertices[] = {
//		// positions          // texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
//		 5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//
//		 5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//		 5.0f, -0.5f, -5.0f,  2.0f, 2.0f
//	};
//
//	Shader shader("shader/depth_testing.vs", "shader/depth_testing.fs");
//	Shader outlineshader("shader/shadersinglecolor.vs", "shader/shadersinglecolor.fs");
//	
//	bool ret = shader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -2;
//	}
//
//	ret = outlineshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return -3;
//	}
//
//	unsigned int cubevao, cubevbo;
//
//	glGenVertexArrays(1, &cubevao);
//	glGenBuffers(1, &cubevbo);
//
//	glBindVertexArray(cubevao);
//	glBindBuffer(GL_ARRAY_BUFFER, cubevbo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	unsigned int planevao, planevbo;
//
//	glGenVertexArrays(1, &planevao);
//	glGenBuffers(1, &planevbo);
//
//	glBindVertexArray(planevao);
//	glBindBuffer(GL_ARRAY_BUFFER, planevbo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	int ierr = 0;
//	unsigned int cubetex = loadtexture("marble.jpg",&ierr);
//	unsigned int floortex = loadtexture("metal.png",&ierr);
//
//	shader.use();
//	shader.setInt("texture1", 0);
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_STENCIL_TEST);
//	glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
//	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
//
//	while (!glfwWindowShouldClose(win)) {
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//
//		// draw floor
//		shader.use();
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 proj = glm::perspective(glm::radians(45.0f), 
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		shader.setMat4("model", model);
//		shader.setMat4("view", view);
//		shader.setMat4("proj", proj);
//
//		glStencilMask(0x00);
//		glBindVertexArray(planevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, floortex);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		//draw cube
//		glStencilFunc(GL_ALWAYS, 1, 0xFF);
//		glStencilMask(0xFF);
//		glBindVertexArray(cubevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubetex);
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(0);
//
//		// draw outline
//		float scale = 1.1f;
//		glStencilMask(0x00);
//		glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
//		glDisable(GL_DEPTH_TEST);
//
//		outlineshader.use();
//
//		outlineshader.setMat4("view", view);
//		outlineshader.setMat4("proj", proj);
//
//		glBindVertexArray(cubevao);
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		model = glm::scale(model, glm::vec3(scale,scale,scale));
//		outlineshader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(scale, scale, scale));
//		outlineshader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(0);
//
//		glStencilMask(0xFF);
//		glStencilFunc(GL_ALWAYS, 0, 0xFF);
//		glEnable(GL_DEPTH_TEST);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &cubevao);
//	glDeleteVertexArrays(1, &planevao);
//	glDeleteBuffers(1, &cubevbo);
//	glDeleteBuffers(1, &planevbo);
//
//	glfwTerminate();
//	return 0;
//}

//int main() {
//	if (!glfwInit()) exit(EXIT_FAILURE);
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
//		"framebuffer", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	float cubeVertices[] = {
//		// positions          // texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//	float planeVertices[] = {
//		// positions          // texture Coords 
//		 5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//
//		 5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
//		 5.0f, -0.5f, -5.0f,  2.0f, 2.0f
//	};
//	float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
//		// positions   // texCoords
//		-1.0f,  1.0f,  0.0f, 1.0f,
//		-1.0f, -1.0f,  0.0f, 0.0f,
//		 1.0f, -1.0f,  1.0f, 0.0f,
//
//		-1.0f,  1.0f,  0.0f, 1.0f,
//		 1.0f, -1.0f,  1.0f, 0.0f,
//		 1.0f,  1.0f,  1.0f, 1.0f
//	};
//
//	unsigned int cubevao, cubevbo;
//	glGenVertexArrays(1, &cubevao);
//	glGenBuffers(1, &cubevbo);
//
//	glBindVertexArray(cubevao);
//	glBindBuffer(GL_ARRAY_BUFFER, cubevbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), 
//		cubeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//
//	unsigned int planevao, planevbo;
//	glGenVertexArrays(1, &planevao);
//	glGenBuffers(1, &planevbo);
//
//	glBindVertexArray(planevao);
//	glBindBuffer(GL_ARRAY_BUFFER, planevbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices),
//		planeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//
//	unsigned int quadvao, quadvbo;
//	glGenVertexArrays(1, &quadvao);
//	glGenBuffers(1, &quadvbo);
//
//	glBindVertexArray(quadvao);
//	glBindBuffer(GL_ARRAY_BUFFER, quadvbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices),
//		quadVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
//
//	int ierr = 0;
//	unsigned int cubeTexture  = loadtexture("container.jpg",&ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	unsigned int floorTexture = loadtexture("metal.png",&ierr);
//	if (ierr != 0) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	Shader framebuffershader("shader/framebuffer.vs",
//							"shader/framebuffer.fs");
//	Shader framebuffer_screenshader("shader/framebuffer_screen.vs", 
//									"shader/framebuffer_screen.fs");
//
//	bool ret = framebuffershader.compile();
//	if (!ret) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	ret = framebuffer_screenshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	framebuffershader.use();
//	framebuffershader.setInt("texture1", 0);
//
//	framebuffer_screenshader.use();
//	framebuffer_screenshader.setInt("screenTexture", 0);
//
//	// framebuffer
//	unsigned int framebuffer;
//	glGenFramebuffers(1, &framebuffer);
//	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//
//	// tex
//	unsigned int texColorBuffer;
//	glGenTextures(1, &texColorBuffer);
//	glBindTexture(GL_TEXTURE_2D, texColorBuffer);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCR_WIDTH, SCR_HEIGHT, 
//		0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, 
//		GL_TEXTURE_2D, texColorBuffer, 0);
//
//	//rbo
//	unsigned int rbo;
//	glGenRenderbuffers(1, &rbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 
//		SCR_WIDTH, SCR_HEIGHT);
//	glBindRenderbuffer(GL_RENDERBUFFER, 0);
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, 
//		GL_RENDERBUFFER, rbo);
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete" << endl;
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glEnable(GL_DEPTH_TEST);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//wireframe mode
//		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		
//
//		framebuffershader.use();
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 proj = glm::perspective(glm::radians(camera.Zoom),
//			(float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//
//		framebuffershader.setMat4("model", model);
//		framebuffershader.setMat4("view", view);
//		framebuffershader.setMat4("proj", proj);
//
//		// cubes
//		glBindVertexArray(cubevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubeTexture);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		framebuffershader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		framebuffershader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		// floor
//		glBindVertexArray(planevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, floorTexture);
//		framebuffershader.setMat4("model", glm::mat4(1.0f));
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//		glBindVertexArray(0);
//
//		// now bind back to default framebuffer and draw a quad plane 
//		// with the attached framebuffer color texture
//
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//		glDisable(GL_DEPTH_TEST);
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		framebuffer_screenshader.use();
//		glBindVertexArray(quadvao);
//		glBindTexture(GL_TEXTURE_2D, texColorBuffer);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &cubevao);
//	glDeleteVertexArrays(1, &planevao);
//	glDeleteVertexArrays(1, &quadvao);
//	glDeleteBuffers(1, &cubevbo);
//	glDeleteBuffers(1, &planevbo);
//	glDeleteBuffers(1, &quadvbo);
//	glDeleteRenderbuffers(1, &rbo);
//	glDeleteFramebuffers(1, &framebuffer);
//
//	glfwTerminate();
//
//	exit(EXIT_SUCCESS);
//}

//int main() {
//	if (!glfwInit()) return(EXIT_FAILURE);
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
//		"framebuffer", NULL, NULL);
//	if (!win) {
//		glfwTerminate();
//		return(EXIT_FAILURE);
//	}
//
//	glfwMakeContextCurrent(win);
//	glfwSetCursorPosCallback(win, mousec_callback);
//	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		glfwTerminate();
//		return(EXIT_FAILURE);
//	}
//
//	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//
//	// cube texture
//	vector<string> faces = {
//		"skybox/right.jpg",
//		"skybox/left.jpg",
//		"skybox/top.jpg",
//		"skybox/bottom.jpg",
//		"skybox/front.jpg",
//		"skybox/back.jpg"
//	};
//	
//	int ierr = 0;
//	unsigned int skyboxtex = loadcubemap(faces,&ierr);
//	
//	if (ierr != 0) {
//		glDeleteTextures(1, &skyboxtex);
//		glfwTerminate();
//		return(EXIT_FAILURE);
//	}
//
//	ierr = 0;
//	unsigned int cubetex = loadtexture("container.jpg", &ierr);
//	if (ierr != 0) {
//		glDeleteTextures(1, &cubetex);
//		glfwTerminate();
//		return EXIT_FAILURE;
//	}
//
//
//	Shader cubeshader("shader/cube.vs", "shader/cube.fs");
//	Shader skyboxshader("shader/skybox.vs", "shader/skybox.fs");
//
//	bool ret;
//
//	ret = cubeshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return(EXIT_FAILURE);
//	}
//
//	ret = skyboxshader.compile();
//	if (!ret) {
//		glfwTerminate();
//		return EXIT_FAILURE;
//	}
//
//	cubeshader.use();
//	cubeshader.setInt("tex", 0);
//
//	skyboxshader.use();
//	skyboxshader.setInt("skybox", 0);
//
//	float cubeVertices[] = {
//		// positions          // texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	float skyboxVertices[] = {
//		// positions          
//		-1.0f,  1.0f, -1.0f,
//		-1.0f, -1.0f, -1.0f,
//		 1.0f, -1.0f, -1.0f,
//		 1.0f, -1.0f, -1.0f,
//		 1.0f,  1.0f, -1.0f,
//		-1.0f,  1.0f, -1.0f,
//
//		-1.0f, -1.0f,  1.0f,
//		-1.0f, -1.0f, -1.0f,
//		-1.0f,  1.0f, -1.0f,
//		-1.0f,  1.0f, -1.0f,
//		-1.0f,  1.0f,  1.0f,
//		-1.0f, -1.0f,  1.0f,
//
//		 1.0f, -1.0f, -1.0f,
//		 1.0f, -1.0f,  1.0f,
//		 1.0f,  1.0f,  1.0f,
//		 1.0f,  1.0f,  1.0f,
//		 1.0f,  1.0f, -1.0f,
//		 1.0f, -1.0f, -1.0f,
//
//		-1.0f, -1.0f,  1.0f,
//		-1.0f,  1.0f,  1.0f,
//		 1.0f,  1.0f,  1.0f,
//		 1.0f,  1.0f,  1.0f,
//		 1.0f, -1.0f,  1.0f,
//		-1.0f, -1.0f,  1.0f,
//
//		-1.0f,  1.0f, -1.0f,
//		 1.0f,  1.0f, -1.0f,
//		 1.0f,  1.0f,  1.0f,
//		 1.0f,  1.0f,  1.0f,
//		-1.0f,  1.0f,  1.0f,
//		-1.0f,  1.0f, -1.0f,
//
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f,  1.0f,
//		 1.0f, -1.0f, -1.0f,
//		 1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f,  1.0f,
//		 1.0f, -1.0f,  1.0f
//	};
//
//	unsigned int cubevao, cubevbo;
//	glGenVertexArrays(1, &cubevao);
//	glGenBuffers(1, &cubevbo);
//
//	glBindVertexArray(cubevao);
//	glBindBuffer(GL_ARRAY_BUFFER, cubevbo);
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//
//	unsigned int skyboxvao, skyboxvbo;
//	glGenVertexArrays(1, &skyboxvao);
//	glGenBuffers(1, &skyboxvbo);
//	glBindVertexArray(skyboxvao);
//	glBindBuffer(GL_ARRAY_BUFFER, skyboxvbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//	glEnable(GL_DEPTH_TEST);
//	while (!glfwWindowShouldClose(win)) {
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(win);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glm::mat4 model = glm::mat4(1.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 proj = glm::perspective(glm::radians(camera.Zoom),
//			(float)SCR_WIDTH / SCR_HEIGHT,
//			0.1f, 100.0f);
//
//		glDepthMask(GL_FALSE);
//		skyboxshader.use();
//		view = glm::mat4(glm::mat3(camera.GetViewMatrix()));
//		skyboxshader.setMat4("view", view);
//		skyboxshader.setMat4("proj", proj);
//		glBindVertexArray(skyboxvao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxtex);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//		glDepthMask(GL_TRUE);
//
//		cubeshader.use();
//		cubeshader.setMat4("model", model);
//		cubeshader.setMat4("view", camera.GetViewMatrix());
//		cubeshader.setMat4("proj", proj);
//		glBindVertexArray(cubevao);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubetex);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//
//		glfwSwapBuffers(win);
//		glfwPollEvents();
//
//	}
//
//	glDeleteVertexArrays(1, &skyboxvao);
//	glDeleteBuffers(1, &skyboxvbo);
//	glDeleteVertexArrays(1, &cubevao);
//	glDeleteBuffers(1, &cubevbo);
//	glDeleteTextures(1, &cubetex);
//
//	glfwTerminate();
//
//	return (EXIT_SUCCESS);
//}


int main() {

    if (!glfwInit()) return EXIT_FAILURE;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "cubemap", NULL, NULL);
    if (!win) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(win);
    glfwSetCursorPosCallback(win, mousec_callback);
    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

    if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    glEnable(GL_DEPTH_TEST);

    Shader cubeshader("shader/cube-review.vert", "shader/cube-review.frag");
    Shader skyboxshader("shader/skybox-review.vert", "shader/skybox-review.frag");

    bool ret = cubeshader.compile();
    if (!ret) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    ret = skyboxshader.compile();
    if (!ret) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    float cubeVertices[] = {
        // positions          // texture Coords
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    float skyboxVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
    };

    unsigned int cubevao, cubevbo;
    glGenVertexArrays(1, &cubevao);
    glGenBuffers(1, &cubevbo);

    glBindVertexArray(cubevao);
    glBindBuffer(GL_ARRAY_BUFFER, cubevbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int skyvao, skyvbo;
    glGenVertexArrays(1, &skyvao);
    glGenBuffers(1, &skyvbo);

    glBindVertexArray(skyvao);
    glBindBuffer(GL_ARRAY_BUFFER, skyvbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), skyboxVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);

    //unsigned int cubetex = loadtexture("container.jpg",)



    while (!glfwWindowShouldClose(win)) {

        processInput(win);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


        glfwSwapBuffers(win);
        glfwPollEvents();
    }


    glDeleteVertexArrays(1, &cubevao);
    glDeleteBuffers(1, &cubevbo);

    glDeleteVertexArrays(1, &skyvao);
    glDeleteBuffers(1, &skyvbo);

    return EXIT_SUCCESS;
}

