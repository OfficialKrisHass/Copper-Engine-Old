//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Application header. The Application is a class in the Engine Core, any Application
//made with the Copper Engine needs to have a class that derives from this class.
//The Application is going to have functions that Initialize the Application itself, Run the Game Loop
//and shutdown the Application when needed

#pragma once

#include "Copper/Core/Core.h"
#include "Copper/Core/Window.h"

#include "Copper/Debug/Log.h"

#include "Copper/Events/Event.h"
#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Events/KeyEvent.h"
#include "Copper/Events/MouseEvent.h"

namespace Copper {

	class Application {

	public:
		void Initialize();

		void OnEvent(Event& e);
		void Run();

		void Shutdown();

	private:
		bool running = true;
		std::unique_ptr<Window> window;

		EventDispatcher dispatcher;

		bool OnWindowClose(Event& e);

	};

}