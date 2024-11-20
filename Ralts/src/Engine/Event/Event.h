#pragma once
#include "../../pch.h"

namespace Engine {

    void windowCloseCallback(GLFWwindow *window);

    class Event {
    public:
        ~Event() {}
        Event(const Event&) = delete;
        Event& operator=(const Event&) = delete;

        static Event& ref() {
            static Event instance;
            return instance;
        }

        void poll();
        void init();

    private:
        Event();

    };

    static Event& event = Event::ref();

    

}