//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Core Window File. Here we make a Core Window Class that each platform will
//derive from and implement it their way. Here we only declare methods that we are going
//to need and nothing more so we only need this header file, no source file.

#pragma once

#include "cupch.h"

#include "Copper/Core/Core.h"
#include "Copper/Events/Event.h"

namespace Copper {

	//Struct for holding the Window Properties such as width and height.
	struct WindowProps {

		//Variables blah blah
		unsigned int width;
		unsigned int height;
		const char* title;

		//Constructor to set the Variables, and also give some sort of default if we don't specify anything
		WindowProps(const char* title = "Copper Engine", unsigned int width = 1280, unsigned int height = 720) : title(title), width(width), height(height) {}

	};

	//The Core Window Class
	class Window {

	public:
		//A shorter version that we can use for setting the callback for Window Events
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		//A Static Create function that for now will be implemented in the WindowsWindow file and always
		//return a Windows Window
		static Window* Create(const WindowProps& props = WindowProps());

		//Virtual functions that will be implemented by the specific Platform implementaion of the Window
		//Getting the Window Data
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual float GetAspectRatio() const = 0;

		//Setting and getting information about the current state of the Window
		virtual void SetVSync(bool enabled) = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual bool IsVSync() const = 0;
		virtual bool ShouldClose() const = 0;

		//Function that returns a pointer to the Window Handle. In GLFW this would be GLFWwindow pointer
		virtual void* GetWindowPointer() const = 0;

		//Update Function will be called every frame
		virtual void OnUpdate() = 0;

	};

}