#include <glad/glad.h>
#include <GLFW/glfw3.h>

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


    while (!glfwWindowShouldClose(win)) {
        glClearColor(0.2f, 0.4f, 0.4f, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}