#pragma once

namespace Engine
{

    class Timer
    {
    public:
        ~Timer() {}
        Timer(const Timer &) = delete;
        Timer &operator=(const Timer &) = delete;
        static Timer &ref()
        {
            static Timer instance;
            return instance;
        }

        void tick();
        void init();
        inline float deltaTime() const { return m_deltaTime; }

    private:
        Timer(); 
        float m_lastFrame, m_deltaTime;
    };

    static Timer &timer = Timer::ref();
}
