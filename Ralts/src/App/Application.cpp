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
        Engine::WindowProps props("Ralts", 1280, 720, true,
                                  std::bind(&Application::onEvent, this, std::placeholders::_1));
        m_window = std::make_unique<Engine::Window>(props);
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