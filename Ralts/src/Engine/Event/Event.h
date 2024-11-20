#pragma once
#include "../Core/Macro.h"

namespace Engine
{

    class Event
    {
    public:
        ~Event() {}
        Event(const Event &) = delete;
        Event &operator=(const Event &) = delete;

        static Event &ref()
        {
            static Event instance;
            return instance;
        }

        void poll();
        void init();

    private:
        Event();
    };

    static Event &event = Event::ref();

}