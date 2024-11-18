#pragma once
#include "Context.h"

namespace Engine {

    struct WindowProps {
        std::string title;
        unsigned int width, height;
        bool vsync;

        WindowProps(const std::string& title = "Ralts",
                    unsigned int width = 1280,
                    unsigned int height = 720,
                    bool vsync = true)
            : title(title), width(width), height(height), vsync(vsync) {}
    };

    class Window {
    public:
        Window(const WindowProps& props);
        ~Window();

        inline unsigned int getWidth() const { return m_data.width; }
        inline unsigned int getHeight() const { return m_data.height; }
        inline bool isVsync() const { return m_data.vsync; }

        inline void setVsync(bool enabled) { m_data.vsync = enabled; }
        void shutdown();
        void update();

    private:
        WindowProps m_data;
        GLFWwindow* m_window;
        std::unique_ptr<Context> m_context;
    };
}