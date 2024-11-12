#pragma once
#include <GLFW/glfw3.h>

namespace App {
    class Application { 
    public:

        static Application& getInstance() {
            static Application instance;
            return instance;
        }

    private:
        Application();
        ~Application();
        Application(const Application&) = delete;


        bool isRunning;
        GLFWwindow* window;
    };

    static Application& app = Application::getInstance();
}