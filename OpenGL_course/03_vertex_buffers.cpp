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

    // Vertex buffer
    float positions[6] = { // data
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };
    unsigned int buffer;
    glGenBuffers(1, &buffer); // (#buffers, unsigned int ID do buffer)
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // colocando o tipo (target) e selecionando o buffer (estou a ponto de usar)
    glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW); // target, tamanho, dados, tipo de uso (ver documentação)

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw call para o vertex buffer criado
        glDrawArrays(GL_TRIANGLES, 0, 3); // índice de início e número de índices

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "\n\n";
    return 0;
}
