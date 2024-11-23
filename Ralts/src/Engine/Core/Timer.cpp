#include "Timer.h"
#include "../engine.h"

namespace Engine
{

    Timer::Timer(): m_lastFrame(0.0f), m_deltaTime(0.0f) 
    {
    }
    
    void Timer::init()
    {
    }

    void Timer::tick()
    {
        m_deltaTime = glfwGetTime() - m_lastFrame;
        m_lastFrame = glfwGetTime();
    }
}