//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "Log.h"

#ifdef CU_DEBUG

#include "spdlog/sinks/stdout_color_sinks.h"

#endif

namespace Copper {

	std::shared_ptr<spdlog::logger> Logger::engineLogger;
	std::shared_ptr<spdlog::logger> Logger::editorLogger;

	void Logger::Initialize() {

#ifdef CU_DEBUG

		spdlog::set_pattern("%^[%T] %n: %v%$");

		engineLogger = spdlog::stdout_color_mt("Engine");
		engineLogger->set_level(spdlog::level::trace);

		editorLogger = spdlog::stdout_color_mt("Editor");
		editorLogger->set_level(spdlog::level::trace);

#endif

	}

}