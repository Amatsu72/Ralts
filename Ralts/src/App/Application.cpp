#include "Application.h"

namespace App {
    
    void Application::update()
    {
        m_window->update();
    }

    void Application::init()
    {
        m_running = true;
        Engine::WindowProps props;
        m_window = std::make_unique<Engine::Window>(props);
    }

    Application::~Application()
    {
        m_window->shutdown();
    }
}