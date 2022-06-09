#pragma once

#include "Engine/Core/Core.h"

#include "cupch.h"

//NOTE: This Event system is basically a Copy of The Cherno's Event System from his Game Engine
//tutorial series. This entire project was heavily inspired by Hazel Engine and there might be
//several occurences where the code looks similar and it's because a lot of the code from his 
//series was the best way to do it so I might even unconsciously make it in a very similar way
//https://github.com/TheCherno/Hazel Hazel Engine github repository

namespace Copper {

	enum class EventType {

		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

	};

#define Type(type) static EventType GetStaticType() { return EventType::##type; }\
				   virtual EventType GetEventType() const override { return GetStaticType(); }\
				   virtual const char* GetName() const override { return #type; }

	class Event {
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

	public:
		bool handled = false;

	};

	class EventDispatcher {

		template<typename T> using EventFn = std::function<bool(T&)>;

	public:
		template<typename T> bool Dispatch(EventFn<T> func, Event& event) {

			if (!event.handled) {

				if (event.GetEventType() == T::GetStaticType()) {

					event.handled = func(*(T*) &event);
					return true;

				}

			}

			return false;

		}

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {

		return os << e.ToString();

	}

}