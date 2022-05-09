//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//The Header for the Windows Implementation of the Window. Here we give the functions
//that were declared in the Base Window class functionality. At the moment we are using
//GLFW as our Window Library but later we should switch to DirectX

#pragma once

#include "cupch.h"

#include "Copper/Core/Window.h"
#include "Copper/Debug/Log.h"

#include <GLFW/glfw3.h>

namespace Copper {

	//The Windows Implementation of the Window Class
	class WindowsWindow : public Window {

	public:
		//Constructor and Destructor
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		//Functions to get the Window Data
		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }
		inline float GetAspectRatio() const override { return static_cast<float>(data.width) / data.height; }

		//Functions to Modify the Window
		void SetVSync(bool enabled) override;
		inline void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }

		//Functions to get the state of the Window
		inline bool IsVSync() const override { return data.VSync; }
		inline bool ShouldClose() const override { return false; }

		//Function to get the Window Handle (in this case GLFWwindow*)
		inline void* GetWindowPointer() const override { return window; }

		//Update Function
		void OnUpdate() override;

	private:
		//Struct that holds the Window Data
		struct WindowData {

			const char* title;
			unsigned int width, height;
			bool VSync;

			//Callback Function that is called to handle the Window Events. In our case
			//it's Application::OnEvent because that function is the main Event handling
			//Function of the Engine
			EventCallbackFn eventCallback;

		};

		//The Window Data and pointer to the GLFWwindow handle
		WindowData data;
		GLFWwindow* window;

	};

}