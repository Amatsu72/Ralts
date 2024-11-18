#pragma once
#include "../engine.h"

namespace Engine {

    class Context {
    public:
        Context(GLFWwindow* m_window):m_windowHandle(m_window) {}
        ~Context() {}

        void init();
        void swapBuffers();

    private:
        GLFWwindow* m_windowHandle;
    };
}