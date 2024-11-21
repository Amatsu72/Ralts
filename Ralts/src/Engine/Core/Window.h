#pragma once
#include "Context.h"
#include "../Event/AppEvent.h"


namespace Engine
{

    struct WindowProps
    {
        std::string title;
        unsigned int width, height;
        bool vsync;
        std::function<void(Event &)> callback;
        WindowProps(const std::string &title,
                    unsigned int width,
                    unsigned int height,
                    bool vsync)
            : title(title), width(width), height(height), vsync(vsync) {}
    };

    class Window
    {
    public:
        Window(const WindowProps &props);
        ~Window();

        inline unsigned int getWidth() const { return m_data.width; }
        inline unsigned int getHeight() const { return m_data.height; }
        inline bool isVsync() const { return m_data.vsync; }

        inline void setVsync(bool enabled) { m_data.vsync = enabled; }
        void shutdown();
        void update();

        void setEventCallback(const std::function<void(Event &)> &callback) { m_data.callback = callback; }

    private:
        void setGlfwCallbacks();

        WindowProps m_data;
        GLFWwindow *m_window;
        std::unique_ptr<Context> m_context;
    };
}