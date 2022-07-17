#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

#include <iostream>
using namespace std;

float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
};
unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

const char *vtShaderSrc =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec3 aColor;\n"
"layout(location = 2) in vec2 aTexCord;\n"
"out vec3 ourColor;\n"
"out vec2 ourTexCord;\n"
"void main() {\n"
"gl_Position = vec4(aPos,1.0);\n"
"ourColor = aColor;\n"
"ourTexCord = aTexCord;\n"
"};\0";

const char *fgShaderSrc =
"#version 330 core\n"
"in vec3 ourColor;\n"
"in vec2 ourTexCord;\n"
"uniform sampler2D tex1;\n"
"uniform sampler2D tex2;\n"
"out vec4 FragColor;\n"
"void main() {\n"
"FragColor = mix(texture(tex1,ourTexCord),texture(tex2,ourTexCord),0.2);\n"
"};\0";

int main() {

    int stat = glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* win = glfwCreateWindow(800, 600, "Day 4 Review", NULL, NULL);
    if (!win) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(win);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);

    unsigned VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //texture
    unsigned texture1, texture2;
    unsigned char* data;
    int width, height, nrchannel;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // set wrap and filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    data = stbi_load("container.jpg", &width, &height, &nrchannel, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        cerr << "Failed in loading" << endl;
    }
    stbi_image_free(data);

    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    // set wrap and filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);
    data = stbi_load("awesomeface.png", &width, &height, &nrchannel, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        cerr << "Failed in loading" << endl;
    }

    stbi_image_free(data);

    int success;
    char msgInfo[512];
    unsigned vtShader, fgShader, shaderProg;
    vtShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vtShader, 1, &vtShaderSrc, NULL);
    glCompileShader(vtShader);
    glGetShaderiv(vtShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vtShader, 512, NULL, msgInfo);
        cerr << msgInfo << endl;
        return -1;
    }

    fgShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fgShader, 1, &fgShaderSrc, NULL);
    glCompileShader(fgShader);
    glGetShaderiv(fgShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fgShader, 512, NULL, msgInfo);
        cerr << msgInfo << endl;
        return -1;
    }

    shaderProg = glCreateProgram();
    glAttachShader(shaderProg, vtShader);
    glAttachShader(shaderProg, fgShader);
    glLinkProgram(shaderProg);
    glGetProgramiv(shaderProg, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProg, 512, NULL, msgInfo);
        cerr << msgInfo << endl;
        return -1;
    }

    glDeleteShader(vtShader);
    glDeleteShader(fgShader);

    glUseProgram(shaderProg);

    glUniform1i(glGetUniformLocation(shaderProg, "tex1"), 0);
    glUniform1i(glGetUniformLocation(shaderProg, "tex2"), 1);

    while (!glfwWindowShouldClose(win)) {
        glClearColor(0.2f, 0.4f, 0.4f, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);

        glUseProgram(shaderProg);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture1);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glDeleteProgram(shaderProg);

    glfwTerminate();
    return 0;
}