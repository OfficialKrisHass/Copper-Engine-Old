#pragma once

#include <spdlog/spdlog.h>

namespace Copper {

	namespace Logger {

		#define Initialize() Logger::Init()

		#ifdef CU_DEBUG
			
			#define Log(...)		Logger::Info(__VA_ARGS__)
			#define LogWarn(...)	Logger::Warn(__VA_ARGS__)
			#define LogTrace(...)	Logger::Trace(__VA_ARGS__)
			#define LogError(...)	Logger::Error(__VA_ARGS__)
			
		#else

			#define Log(...)
			#define LogWarn(...)
			#define LogTrace(...)
			#define LogError(...)

		#endif

		class Logger {

		public:
			static void Init();

			inline static void Info(const char* msg) { logger->info(msg); }
			inline static void Warn(const char* msg) { logger->warn(msg); }
			inline static void Trace(const char* msg) { logger->trace(msg); }
			inline static void Error(const char* msg) { logger->error(msg); }

			template<typename... Args> inline static void Info(const char* fmt, Args&... args) { logger->info(fmt, args...); }
			template<typename... Args> inline static void Warn(const char* fmt, Args&... args) { logger->warn(fmt, args...); }
			template<typename... Args> inline static void Trace(const char* fmt, Args&... args) { logger->trace(fmt, args...); }
			template<typename... Args> inline static void Error(const char* fmt, Args&... args) { logger->erorr(fmt, args...); }

		private:
			static std::shared_ptr<spdlog::logger> logger;

		};

	}

}