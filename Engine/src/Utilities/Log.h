//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Logger File. The Logger is going to have methods that are going to be used by the Application, Editor and Even the Engine.
//These functions need to only work if the Application or Engine is in Debug Mode. And also when the Editor requests a Log it is different
//then when a Application wants to request a log, so they need to do different things.

#pragma once

#include <iostream>

namespace Copper {

#ifdef CU_DEBUG

	#ifdef CU_ENGINE

		#define Log(...)		std::cout << "Normal:   " << __VA_ARGS__ << std::endl;
		#define LogWarn(...)	std::cout << "Warning:  " << __VA_ARGS__ << std::endl;
		#define LogError(...)	std::cout << "Error:   " << __VA_ARGS__ << std::endl;

	#endif

#endif

}