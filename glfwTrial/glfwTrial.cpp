#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
using namespace std;

//day 5 review
//float vertices[] = {
//    // positions          // colors           // texture coords
//     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//};
//unsigned int indices[] = {
//    0, 1, 3, // first triangle
//    1, 2, 3  // second triangle
//};
//
//const char *vtShaderSrc =
//"#version 330 core\n"
//"layout(location = 0) in vec3 aPos;\n"
//"layout(location = 1) in vec3 aColor;\n"
//"layout(location = 2) in vec2 aTexCord;\n"
//"out vec3 ourColor;\n"
//"out vec2 ourTexCord;\n"
//"uniform mat4 transform;\n"
//"void main() {\n"
//"gl_Position = transform * vec4(aPos,1.0);\n"
//"ourColor = aColor;\n"
//"ourTexCord = aTexCord;\n"
//"};\0";
//
//const char *fgShaderSrc =
//"#version 330 core\n"
//"in vec3 ourColor;\n"
//"in vec2 ourTexCord;\n"
//"uniform sampler2D tex1;\n"
//"uniform sampler2D tex2;\n"
//"out vec4 FragColor;\n"
//"void main() {\n"
//"FragColor = mix(texture(tex1,ourTexCord),texture(tex2,ourTexCord),0.2);\n"
//"};\0";
//
//int main() {
//
//    int stat = glfwInit();
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* win = glfwCreateWindow(800, 600, "Day 4 Review", NULL, NULL);
//    if (!win) {
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(win);
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        glfwTerminate();
//        return -1;
//    }
//
//    glViewport(0, 0, 800, 600);
//
//    unsigned VAO, VBO, EBO;
//
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    //texture
//    unsigned texture1, texture2;
//    unsigned char* data;
//    int width, height, nrchannel;
//
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//
//    // set wrap and filter
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//    data = stbi_load("container.jpg", &width, &height, &nrchannel, 0);
//    if (data) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else {
//        cerr << "Failed in loading" << endl;
//    }
//    stbi_image_free(data);
//
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//
//    // set wrap and filter
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//    stbi_set_flip_vertically_on_load(true);
//    data = stbi_load("awesomeface.png", &width, &height, &nrchannel, 0);
//    if (data) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else {
//        cerr << "Failed in loading" << endl;
//    }
//
//    stbi_image_free(data);
//
//    int success;
//    char msgInfo[512];
//    unsigned vtShader, fgShader, shaderProg;
//    vtShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vtShader, 1, &vtShaderSrc, NULL);
//    glCompileShader(vtShader);
//    glGetShaderiv(vtShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetShaderInfoLog(vtShader, 512, NULL, msgInfo);
//        cerr << msgInfo << endl;
//        return -1;
//    }
//
//    fgShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fgShader, 1, &fgShaderSrc, NULL);
//    glCompileShader(fgShader);
//    glGetShaderiv(fgShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetShaderInfoLog(fgShader, 512, NULL, msgInfo);
//        cerr << msgInfo << endl;
//        return -1;
//    }
//
//    shaderProg = glCreateProgram();
//    glAttachShader(shaderProg, vtShader);
//    glAttachShader(shaderProg, fgShader);
//    glLinkProgram(shaderProg);
//    glGetProgramiv(shaderProg, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProg, 512, NULL, msgInfo);
//        cerr << msgInfo << endl;
//        return -1;
//    }
//
//    glDeleteShader(vtShader);
//    glDeleteShader(fgShader);
//
//    glUseProgram(shaderProg);
//
//    glUniform1i(glGetUniformLocation(shaderProg, "tex1"), 0);
//    glUniform1i(glGetUniformLocation(shaderProg, "tex2"), 1);
//
//    while (!glfwWindowShouldClose(win)) {
//        glClearColor(0.2f, 0.4f, 0.4f, 1.0);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glBindVertexArray(VAO);
//
//        glUseProgram(shaderProg);
//
//        //glm
//        glm::mat4 trans = glm::mat4(1.0f);
//        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
//
//        glUniformMatrix4fv(glGetUniformLocation(shaderProg, "transform"),
//            1,
//            GL_FALSE,
//            glm::value_ptr(trans));
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D,texture1);
//
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        glfwSwapBuffers(win);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1,&VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//
//    glDeleteProgram(shaderProg);
//
//    glfwTerminate();
//    return 0;
//}

// day 6

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
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 proj;\n"
"void main() {\n"
"gl_Position = proj*view*model*vec4(aPos,1.0);\n"
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
    if (!stat) {
        cerr << "glfw init fail" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* win = glfwCreateWindow(800, 600, "Day 6", NULL, NULL);
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
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    unsigned vtShader, fgShader, shaderProg;
    int success;
    char msgInfo[512];

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

    unsigned char* data;
    int width, height, nrchannel;

    unsigned tex1, tex2;

    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &tex1);
    glBindTexture(GL_TEXTURE_2D, tex1);

    //wrap and filter
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
        cerr << "Fail in loading jpg" << endl;
    }

    stbi_image_free(data);

    glGenTextures(1, &tex2);
    glBindTexture(GL_TEXTURE_2D, tex2);

    //wrap and filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    data = stbi_load("awesomeface.png", &width, &height, &nrchannel, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        cerr << "Fail in loading jpg" << endl;
    }

    stbi_image_free(data);

    glUseProgram(shaderProg);
    glUniform1i(glGetUniformLocation(shaderProg, "tex1"), 0);
    glUniform1i(glGetUniformLocation(shaderProg, "tex2"), 1);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 
        0.1f, 100.0f);

    unsigned modelLoc = glGetUniformLocation(shaderProg, "model");
    unsigned viewLoc  = glGetUniformLocation(shaderProg, "view");
    unsigned projLoc  = glGetUniformLocation(shaderProg, "proj");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE,glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    while (!glfwWindowShouldClose(win)) {

        glClearColor(0.2, 0.4, 0.4, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProg);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex1);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, tex2);

        glBindVertexArray(VAO);

        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glDeleteTextures(1, &tex1);
    glDeleteTextures(1, &tex2);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
    return 0;
}