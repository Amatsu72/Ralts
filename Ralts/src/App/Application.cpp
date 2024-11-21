#include "Application.h"

namespace App
{

    void Application::update()
    {
        m_window->update();
    }

    void Application::onEvent(Engine::Event &e)
    {
    }

    void Application::init()
    {
        m_running = true;
        Engine::WindowProps props("Ralts", 1280, 720, true);
        m_window = std::make_unique<Engine::Window>(props);
        m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

        
    }

    Application::~Application()
    {
        m_window->shutdown();
    }

    bool Application::onWindowClose(Engine::Event &e)
    {
        return false;
    }

    bool Application::onWindowResize(Engine::Event &e)
    {
        return false;
    }

}