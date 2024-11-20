#pragma once
#include "../Engine/engine.h"

namespace App {
    class Application { 
    public:
        ~Application();
        Application(const Application &) = delete;
        Application& operator=(const Application &) = delete;

        static Application& ref() {
            static Application instance;
            return instance;
        }

        void update();
        void onEvent(Engine::Event& e);

        void init();
        bool isRunning() const { return m_running; }

    private:
        Application() {}  

        bool onWindowClose(Engine::Event& e);
        bool onWindowResize(Engine::Event& e);

        bool m_running = true;
        std::unique_ptr<Engine::Window> m_window;
    };

    static Application& app = Application::ref();
}