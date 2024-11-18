#include "Context.h"

namespace Engine {
    void Context::init() {
        glfwMakeContextCurrent(m_windowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if(!status) {
            std::cout << "Failed to initialize GLAD" << std::endl;  
        }
    }

    void Context::swapBuffers() {
        glfwSwapBuffers(m_windowHandle);
    }

}