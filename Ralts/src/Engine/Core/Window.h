#pragma once
#include "Context.h"
#include "../Event/Event.h"

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
                    bool vsync,
                    std::function<void(Event &)> callback)
            : title(title), width(width), height(height), vsync(vsync), callback(callback) {}
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
        WindowProps m_data;
        GLFWwindow *m_window;
        std::unique_ptr<Context> m_context;
    };
}