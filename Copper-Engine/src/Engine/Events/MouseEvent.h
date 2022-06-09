#pragma once

#include "Engine/Events/Event.h"

namespace Copper {

	class MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(float x, float y) : x(x), y(y) {}

		inline float GetX() const { return x; }
		inline float GetY() const { return y; }

		std::string ToString() const override {

			std::stringstream ss;
			ss << "MouseMovedEvent: " << x << ", " << y;

			return ss.str();

		}

		Type(MouseMoved)

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

		Type(MouseScrolled)

	private:
		float xOffset;
		float yOffset;

	};

	class MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() const { return button; }

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

		Type(MouseButtonPressed)

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {

			std::ostringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;

			return ss.str();

		}

		Type(MouseButtonReleased)

	};

}