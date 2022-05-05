//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "Application.h"

#include <GLFW/glfw3.h>

namespace Copper {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	void Application::Initialize() {

		//Here we initialize parts of the engine that need to be initializéd
		LogTrace("-------Application Initialization-------");

		Logger::Initialize();

		//Test if our Logging system functions correctly
		Log("you are too cute!");
		LogError("Variable 'No u' not defined");
		LogTrace("");

		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		//Inform the User that the Application Initialization was successful
		Log("Application Succesfully Initialized!");
		LogTrace("----------------------------------------");

	}

	void Application::Run() {

		//This is the main Application Loop here we handle events, rendering input, everything that needs to be handled during runtime
		LogTrace("\n-------Application Game Loop-------");
		Log("Application Entered Game Loop");
		LogTrace("-----------------------------------");

		while (running) {

			glClearColor(0.18f, 0.18f, 0.18f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			window->OnUpdate();

		}

	}

	void Application::OnEvent(Event& e) {

		Log(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose), e);

	}

	void Application::Shutdown() {

		//Here we Shutdown and clear everything left behind the application before successfully exiting the Application
		LogTrace("\n-------Application Shutdown-------");
		Log("Application Shutdown requested");
		LogTrace("----------------------------------");

	}

	bool Application::OnWindowClose(Event& e) {

		Log(e);
		running = false;

		return false;

	}

}