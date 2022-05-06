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

	std::shared_ptr<spdlog::logger> Logger::consoleLogger;

	void Logger::Initialize() {

#ifdef CU_DEBUG

		spdlog::set_pattern("%^[%T] %n: %v%$");

		consoleLogger = spdlog::stdout_color_mt("Logger");
		consoleLogger->set_level(spdlog::level::trace);

#endif

	}

}