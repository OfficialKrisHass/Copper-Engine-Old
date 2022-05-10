//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//In this file we define Keyboard and Input category events. Events such as KeyPressed and KeyReleased.

#pragma once

#include "Event.h"

namespace Copper {

	//Core KeyEvent class, stores the things that both KeyPressed and Released will need so we don't have to type
	//all of this 2 times (yeah ik I'm lazy)
	class KeyEvent : public Event {

	public:
		inline int GetKeyCode() const { return keyCode; } //Function to get the keycode of the event

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput) //Implementation of the functions required for every Event

	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) {} //A Protected constructor so that only class deriving from this one can access the constructor

		int keyCode; //KeyCode is a number that represents what key we pressed

	};

	//KeyPressedEvent is when well when you press a Key on your keyboard. there is also how many repeats you have
	//because when you hold a key you want to type it once, wait for a little while and then write multiple of the letters
	//
	//Example :
	//Lets say we are holding the key 'A' for 5 seconds
	//a......aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	//
	//The repeat count is just how many times we want to repeat the letter being written after the short stop after the first one
	class KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount) {} //Constructor to just set the KeyCode and repeatCount

		inline int GetRepeatCount() const { return repeatCount; } //Function to get the Repeat Count

		//KeyPressed ToString implementation. ToString is used when we want to type the information from the event, in this case
		//the name of the Event, the keycode and Repeat count
		std::string ToString() const override {

			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";

			return ss.str();

		}

		EVENT_CLASS_TYPE(KeyPressed) //Implementation of the Functions required by every Event

	private:
		int repeatCount; //RepeatCount as mentioned previously is just how many rimes we want to repeat the letter after the first one

	};

	//KeyReleasedEvent is when you stop holding a key (wow, how did I know that ? magic). This is more simpler since
	//there is no Repeat Count, just the KeyCode of the key that was released.
	class KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {} //Constructor to again set the variables

		//KeyReleasedEvent ToString implementation.ToString is used when we want to type the information from the event, in this case
		//the name of the Event and the keycode
		std::string ToString() const override {

			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;

			return ss.str();

		}

		EVENT_CLASS_TYPE(KeyReleased) //Implementation of the functions required by every Event

	};

	class KeyTypedEvent : public KeyEvent {

	public:
		KeyTypedEvent(int keyCode) : KeyEvent(keyCode) {} //Constructor to just set the KeyCode and repeatCount

		//KeyPressed ToString implementation. ToString is used when we want to type the information from the event, in this case
		//the name of the Event, the keycode and Repeat count
		std::string ToString() const override {

			std::stringstream ss;
			ss << "KeyTypedEvent: " << keyCode;

			return ss.str();

		}

		EVENT_CLASS_TYPE(KeyTyped) //Implementation of the Functions required by every Event

	};

}