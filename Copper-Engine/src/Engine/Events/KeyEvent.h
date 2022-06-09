#pragma once

#include "Engine/Events/Event.h"

namespace Copper {

	class KeyEvent : public Event {

	public:
		inline int GetKeyCode() const { return keyCode; }

	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) {}

		int keyCode;

	};

	class KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override {

			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";

			return ss.str();

		}

		Type(KeyPressed)

	private:
		int repeatCount;

	};

	class KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override {

			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;

			return ss.str();

		}

		Type(KeyReleased)

	};

}