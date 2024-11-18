#include "Window.h"

namespace Engine {

    Window::Window(const WindowProps& props) : m_data(props)
    {
        int success = glfwInit();
        if(!success) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        auto monitor = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, monitor->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, monitor->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, monitor->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, monitor->refreshRate);

        m_window = glfwCreateWindow((int)m_data.width, (int)m_data.height, m_data.title.c_str(), nullptr, nullptr);

        m_context = std::make_unique<Context>(m_window);
        m_context->init();

        glfwSetWindowUserPointer(m_window, &m_data);
		setVsync(true);
    }

    void Window::update()
    {
        // glfwPollEvents();
        // m_context->swapBuffers();

        while(!glfwWindowShouldClose(m_window))
        {
            glfwPollEvents();
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(m_window);
        }
    }
    
    Window::~Window()
    {
        shutdown();
    }
    
    void Window::shutdown() 
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}