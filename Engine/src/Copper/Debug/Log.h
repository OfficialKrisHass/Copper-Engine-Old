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

#include "cupch.h"
#include "Copper/Core/Core.h"

#ifdef CU_DEBUG

	#include "spdlog/spdlog.h"
	#include "spdlog/fmt/ostr.h"

#else

	namespace spdlog {

		class logger;

	}

#endif

namespace Copper {

#ifdef CU_DEBUG

	#ifdef CU_ENGINE

		#define Log(...)		Copper::Logger::GetLogger()->info(__VA_ARGS__)
		#define LogTrace(...)   std::cout << __VA_ARGS__ << std::endl
		#define LogWarn(...)	Copper::Logger::GetLogger()->warn(__VA_ARGS__)
		#define LogError(...)	Copper::Logger::GetLogger()->error(__VA_ARGS__)

	#endif

#elif CU_RELEASE

	#ifdef CU_ENGINE

		#define Log(...)
		#define LogTrace(...)
		#define LogWarn(...)
		#define LogError(...)

	#endif

#endif

	class Logger {

	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return consoleLogger; }

	private:
		static std::shared_ptr<spdlog::logger> consoleLogger;

	};

}