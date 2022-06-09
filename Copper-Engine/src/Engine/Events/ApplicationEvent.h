#pragma once

#include "Engine/Events/Event.h"

namespace Copper {

	class WindowResizeEvent : public Event {

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {} //Constructor to set the new Window Dimensions

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override {

			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;

			return ss.str();

		}

		Type(WindowResize)

	private:
		unsigned int width;
		unsigned int height;

	};

	class WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {}

		Type(WindowClose)

	};

}