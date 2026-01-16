#include <GL/glew.h>
#include <GLFW/glfw3.h> // Para criar janelas e gerenciar contextos OpenGL.
#include <iostream>


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;  

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // glew precisa que o contexto OpenGL já esteja definido antes
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Glew error\n";
        return -1;
    }

    std::cout << "GL version: " << glGetString(GL_VERSION) << "\n";

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "\n\n";
    return 0;
}
