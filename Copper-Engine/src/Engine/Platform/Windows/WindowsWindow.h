#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Core/Window.h"

struct GLFWwindow;

namespace Copper {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(WindowProps props);
		//virtual ~WindowsWindow();

		inline virtual uint32_t Width()  override { return data.width; }
		inline virtual uint32_t Height() override { return data.height; }
		inline virtual float AspectRatio() override { return static_cast<float>(data.width) / data.height; }

		inline void SetEventCallback(EventCallback callback) override { data.eventCallback = callback; }

		virtual void Update() override;

		virtual void Shutdown() override;

	private:

		struct WindowData {

			uint32_t width;
			uint32_t height;
			std::string title;

			EventCallback eventCallback;

		};

		WindowData data;
		GLFWwindow* window;

	};

}