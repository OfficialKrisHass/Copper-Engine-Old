#pragma once

#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Copper {

	#define LoggerInit() Logger::Initialize()

	#ifdef CU_DEBUG
		
		#define Log(...)		Logger::GetLogger()->info(__VA_ARGS__)
		#define LogWarn(...)	Logger::GetLogger()->warn(__VA_ARGS__)
		#define LogTrace(...)	Logger::GetLogger()->trace(__VA_ARGS__)
		#define LogError(...)	Logger::GetLogger()->error(__VA_ARGS__)

		#define Empty()			std::cout << "" << std::endl
		#define Header(...)		Logger::GetLogger()->trace(__VA_ARGS__); std::cout << "" << std::endl
		
	#else

		#define Log(...)
		#define LogWarn(...)
		#define LogTrace(...)
		#define LogError(...)

		#define Empty()
		#define Header(...)

	#endif

	class Logger {

	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger> GetLogger() { return logger; }

	private:
		static std::shared_ptr<spdlog::logger> logger;

	};

}