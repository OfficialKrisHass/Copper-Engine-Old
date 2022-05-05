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

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float x;
		float y;

	};

	class MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {}

		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }

		std::string ToString() const override {

			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;

			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float xOffset;
		float yOffset;

	};

	class MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button) : button(button) {}

		int button;

	};

	class MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {

			std::ostringstream ss;
			ss << "MouseButtonPressedEvent: " << button;

			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {

			std::ostringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;

			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}