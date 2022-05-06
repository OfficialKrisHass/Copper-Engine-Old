//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Base Event file. Here we create the base Event class for the Event System.
//The Event system is an important system that is the base for handling events and debuging them.
//In this file we only declare the functions and basic stuff each event needs and then in
//specific Event files we will make definitions of these functions.

#pragma once

#include "cupch.h"
#include "Copper/Core/Core.h"

//NOTE: This Event system is basically a Copy of The Cherno's Event System from his Game Engine
//tutorial series. This entire project was heavily inspired by Hazel Engine and there might be
//several occurences where the code looks similar and it's because a lot of the code from his 
//series was the best way to do it so I might even unconsciously make it in a very similar way
//https://github.com/TheCherno/Hazel Hazel Engine github repository

namespace Copper {

	//Enum For each possible Event Type
	enum class EventType {

		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

	};

	//Enum for Categories of Events.
	//NOTE: Events can be in multiple categories, like KeyPressedEvent is in Input and Keyboard category, that's why we have specific
	//bits for each Event Category, so that the Event can be OR-ed into one number (like 01100)
	enum EventCategory {

		None = 0,

		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)

	};

//This define is to implement the needed functions so that we won't have to write all of this
//each time we are making a new Event, we can just use this define and specify the Event Type
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

//The same goes for here, but for specifying functions dependent on EventCategory
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//The Base Event Class, Specific Events derive from this class
	class Event {
		//We need to set the EventDispatcher class as a friend so that it's the only class
		//That can access private viariables (in this case the handled bool)
		friend class EventDispatcher;

	public:
		//The same functions from the Defines but this time they are just virtual functions
		//that new Event classes will override
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

	public:
		//a Bool that specifies if this Event was already Handled, becuase if it was
		//we don't need to handle it the second time
		bool handled = false;

	};

	//The Event Dispatcher is a tool that we can use to Dispatch events. We can create an Event Dispatcher,
	//and Dispatch an event and it will check if the Event is of a specific Type we've given, and if yes it will
	//call the Function that was given with the event
	//
	//Example:
	//void OnEvent(Event e) {
	//
	//		EventDispatcher dispatcher;
	//		dispatcher.Dispatch<EventType>(function to call if Event is the right EventType, Event);
	//
	//}
	class EventDispatcher {

		//A template so that we don't have to type 'std::function<bool>(T&)' everytime we want to use a function
		//as a parameter
		template<typename T> using EventFn = std::function<bool(T&)>;

	public:
		//The Dispatch function that takes a 'T' Event template parameter, the Event we want to dispatch and
		//the function to call if the Event is the EventType as the Event template parameter.
		template<typename T> bool Dispatch(EventFn<T> func, Event& event) {

			//Check if the event has already been handled
			if (!event.handled) {

				//DEBUG: std::cout << event.GetName() << " has not been handled" << std::endl;

				//Check if the Event We are handling is the correct EventType as the one we are looking for
				if (event.GetEventType() == T::GetStaticType()) {

					//DEBUG: std::cout << event.GetName() << " is the correct EventType" << std::endl;

					//Call the function that was given and set the Event handled bool to whatever the function returns
					event.handled = func(*(T*)&event);
					return true;

				}

				//DEBUG: std::cout << event.GetName() << " is not the correct EventType!" << std::endl;

			} //DEBUG: else { std::cout << event.GetName() << " has already been handled!" << std::endl; }

			return false;

		}

	};

	//A operator function so that we can easily Debug The event with our Logging library
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {

		return os << e.ToString();

	}

}