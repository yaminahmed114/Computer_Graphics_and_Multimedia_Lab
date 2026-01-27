#include "glad.h"
#include "glfw3.h"

#include <iostream>

// Function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// First letter of your name
const int CLOSE_KEY = GLFW_KEY_M;  // M for Md.Fizul Islam Yamin

int main()
{
    // ------------------------------
    // Initialize GLFW
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // ------------------------------
    // Create Window
    // ------------------------------
    GLFWwindow* window = glfwCreateWindow(
        SCR_WIDTH,
        SCR_HEIGHT,
        "Md.Fizul Islam Yamin",   // Window Title = Full Name
        NULL,
        NULL
    );

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // ------------------------------
    // Initialize GLAD
    // ------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "Program started successfully!" << std::endl;
    std::cout << "Press 'M' to close the window." << std::endl;

    // ------------------------------
    // Render Loop
    // ------------------------------
    while (!glfwWindowShouldClose(window))
    {
        // Input handling
        processInput(window);

        // Render cyan background
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f); // Cyan color
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    return 0;
}

// ------------------------------
// Handle Keyboard Input
// ------------------------------
void processInput(GLFWwindow *window)
{
    // Close if ESC pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Close if first letter of name pressed (M)
    if (glfwGetKey(window, CLOSE_KEY) == GLFW_PRESS)
    {
        std::cout << "Key 'M' pressed. Closing window..." << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}

// ------------------------------
// Resize Viewport
// ------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
