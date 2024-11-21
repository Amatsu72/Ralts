#include "Window.h"

namespace Engine
{

    // void WindowSizeCallback(GLFWwindow* window, int width, int height)
    // {
    //     WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(window);
    //     data.width = width;
    //     data.height = height;
    //     WindowResizeEvent event(width, height);
    //     data.callback(event);
    // }

    Window::Window(const WindowProps &props) : m_data(props)
    {
        int success = glfwInit();
        if (!success)
        {
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

        setGlfwCallbacks();
    }

    void Window::update()
    {
        // glfwPollEvents();
        // m_context->swapBuffers();

        while (!glfwWindowShouldClose(m_window))
        {
            glfwPollEvents();
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(m_window);
        }
    }

    void Window::setGlfwCallbacks()
    {   
        // glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		data.Width = width;
		// 		data.Height = height;
		// 		WindowResizeEvent event(width, height);
		// 		data.EventCallback(event);
		// 	});
		// glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		WindowCloseEvent event;
		// 		data.EventCallback(event);
		// 	});
		// glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		switch (action)
		// 		{
		// 			case GLFW_PRESS:
		// 			{
		// 				KeyPressedEvent event((KeyCode)key, 0);
		// 				data.EventCallback(event);
		// 				break;
		// 			}
		// 			case GLFW_RELEASE:
		// 			{
		// 				KeyReleasedEvent event((KeyCode)key);
		// 				data.EventCallback(event);
		// 				break;
		// 			}
		// 			case GLFW_REPEAT:
		// 			{
		// 				KeyPressedEvent event((KeyCode)key, 1);
		// 				data.EventCallback(event);
		// 				break;
		// 			}
		// 		}
		// 	});
		// glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		KeyTypedEvent event((KeyCode)keycode);
		// 		data.EventCallback(event);
		// 	});
		// glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		switch (action)
		// 		{
		// 			case GLFW_PRESS:
		// 			{
		// 				MouseButtonPressedEvent event((MouseButton)button);
		// 				data.EventCallback(event);
		// 				break;
		// 			}
		// 			case GLFW_RELEASE:
		// 			{
		// 				MouseButtonReleasedEvent event((MouseButton)button);
		// 				data.EventCallback(event);
		// 				break;
		// 			}
		// 		}
		// 	});
		// glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		// 		data.EventCallback(event);
		// 	});
		// glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
		// 	{
		// 		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		// 		MouseMovedEvent event((float)xPos, (float)yPos);
		// 		data.EventCallback(event);
		// 	});
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