//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "Application.h"

#include "Utilities/Log.h"

namespace Copper {

	void Application::Initialize() {

		int a = 5;
		Log("Hello, World. Var = " << a);
		LogWarn("you are too cute!");
		LogError(" Variable 'No u' not defined");

	}

	void Application::Start() {

		//

	}

	void Application::Shutdown() {

		//

	}

}