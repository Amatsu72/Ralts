#include "Timer.h"
#include "../engine.h"

namespace Engine {

    void Timer::init() {

    }

    void Timer::tick() {
        m_deltaTime = glfwGetTime() - m_lastFrame; 
        m_lastFrame = glfwGetTime();
    }
}