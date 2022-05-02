//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "Application.h"

namespace Copper {

	void Application::Initialize() {

		Logger::Initialize();

		Log("you are too cute!");
		LogError(" Variable 'No u' not defined");

	}

	void Application::Run() {

		//

	}

	void Application::Shutdown() {

		//

	}

}