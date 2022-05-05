//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//In this file we define the Application Category Events such as Window Resize and Window Close.

#pragma once

#include "Event.h"

namespace Copper {

	//WindowReszeEvent is when the Window is resized. It's pretty simple because the only thing we need
	//is to know the dimensions it was resized to.
	class WindowResizeEvent : public Event {

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {} //Constructor to set the new Window Dimensions

		//Functions to get the Dimensions respectively as floats
		//NOTE: Maybe add a third function that would return vector2 with both dimensions
		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		//WindowResizeEvent ToString implementation. ToString is used when we want to type the information from the event, in this case
		//the name of the Event and new dimensions of the Window
		std::string ToString() const override {

			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;

			return ss.str();

		}

		//Implementation of the functions required by every Event
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		//The new dimensions of the window
		unsigned int width;
		unsigned int height;

	};

	//WindowCloseEvent is a very simple Event since it doesn't hold any data it only exists. Again as the name
	//suggests this event is when we Request to Close the window, that's why it's so simple
	class WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {} //Default Constructor

		//Implementation of the functions required by every Event
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

}