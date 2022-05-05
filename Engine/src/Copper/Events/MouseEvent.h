//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//In this file we define the Events for Input and Mouse Event Categories, such as MouseMoved, MouseButtonPressed, etc

#pragma once

#include "Event.h"

namespace Copper {

	//If you are not stupid you know what this Event Does
	//But if you are stupid, it is an event where the Mouse was moved
	class MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(float x, float y) : x(x), y(y) {} //Constructor to set the position to where the mouse was moved

		//Functions to get the new position of the Mouse seperately
		//NOTE: Again, maybe add a third function that will return vector2 with both positions in it
		inline float GetX() const { return x; }
		inline float GetY() const { return y; }

		//MouseMovedEvent ToString Implementations. ToString is used when we want to type the information from the event, in this case
		//the name of the Event and new Positions of the Mouse
		std::string ToString() const override {

			std::stringstream ss;
			ss << "MouseMovedEvent: " << x << ", " << y;

			return ss.str();

		}

		//Implementation of the functions required by every Event
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		//The new position of the Mouse
		float x;
		float y;

	};

	//MouseScrolledEvent is wh... Why am I writing this. it's so fucking obvious what it is so why am I doing this, what's wrong with me
	class MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {} //You already know what this does

		//Blah blah seperate positions of the scroll blah blah
		//NOTE: blah blah
		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }

		//BlahBlahEvent ToString blah implementation. blah blah blah, name blah, blah blah position of the blah scroll
		std::string ToString() const override {

			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;

			return ss.str();

		}

		//Functions blah blah every implementation blah blah
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		//You know what this is, I don't need to explain this
		float xOffset;
		float yOffset;

	};

	//Core MouseButtonEvent class, stores the things that all MouseButton events are going to need.
	class MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() const { return button; } //Function to Get the button connected to this event

		//Implementation of the functions required by every Event
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button) : button(button) {} //Protected Constructor so that only classes that derive from this can access it

		int button; //The Button connected to the Event

	};

	//MouseButtonPressedEvent is when you... you know what, I'm not going to explain this
	class MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {} //Why should I explain this, who wants to know what it does ?

		//Noone cares what this is. I don't need to explain this
		std::string ToString() const override {

			std::ostringstream ss;
			ss << "MouseButtonPressedEvent: " << button;

			return ss.str();

		}

		//This is something that completely noone wants to know
		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	//Why am I doing this to myself, why did I want to have a better commented code so other people can understand it
	//What's wrong with me, why did I decide I want to code, please help me
	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {} //This code is slowly eating me away

		//I'm slowly dying inside, leaving my friends and family, getting closed in in myself
		//doing something because I want to learn somethingg losing my sanity and just dying inside
		std::string ToString() const override {

			std::ostringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;

			return ss.str();

		}

		//I can't do this anymore, Who am I, why am I, The Only thing I know is that I don't like doin this
		//But I have to. But why, is this some sort of game where someone is watching me and reading this
		//using me for their entertainment ?
		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}



























































































































































//I WANT IT TO STOPPOOOPOOPO!!"!!! ! DSF KA LFK FSJK KF