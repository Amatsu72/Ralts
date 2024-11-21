#pragma once
#include "../Core/Macro.h"

namespace Engine
{

    enum class EventType
	{
		None = 0,
		WindowClose, WindowMinimize, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

    enum EventCategory
	{
		None = 0,
		Application	= BIT(0),
		Input		= BIT(1),
		Keyboard	= BIT(2),
		Mouse		= BIT(3),
		MouseButton	= BIT(4)
	};

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
        EventType m_type = EventType::None;
    };

    static Event &event = Event::ref();

}