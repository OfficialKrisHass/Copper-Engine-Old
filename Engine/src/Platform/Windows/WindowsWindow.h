//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#pragma once

#include "cupch.h"

#include "Copper/Core/Window.h"
#include "Copper/Debug/Log.h"

#include <GLFW/glfw3.h>

namespace Copper {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }

		void SetVSync(bool enabled) override;
		inline void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
		inline bool IsVSync() const override { return data.VSync; }
		inline bool ShouldClose() const override { return false; }

		void OnUpdate() override;

	private:
		struct WindowData {

			const char* title;
			unsigned int width, height;
			bool VSync;

			EventCallbackFn eventCallback;

		};

		WindowData data;
		GLFWwindow* window;

	};

}