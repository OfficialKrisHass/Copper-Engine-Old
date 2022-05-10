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

		#define EngineLog(...)			Copper::Logger::GetEngineLogger()->info(__VA_ARGS__)
		#define EngineLogWarn(...)		Copper::Logger::GetEngineLogger()->warn(__VA_ARGS__)
		#define EngineLogError(...)		Copper::Logger::GetEngineLogger()->error(__VA_ARGS__)
		#define EngineLogTrace(...)		std::cout << __VA_ARGS__ << std::endl

		#define EditorLog(...)			Copper::Logger::GetEditorLogger()->info(__VA_ARGS__)
		#define EditorLogWarn(...)		Copper::Logger::GetEditorLogger()->warn(__VA_ARGS__)
		#define EditorLogError(...)		Copper::Logger::GetEditorLogger()->error(__VA_ARGS__)
		#define EditorLogTrace(...)		std::cout << __VA_ARGS__ << std::endl

	#endif

#elif CU_RELEASE

	#ifdef CU_ENGINE

		#define EngineLog(...)
		#define EngineLogTrace(...)
		#define EngineLogWarn(...)
		#define EngineLogError(...)

		#define EditorLog(...)
		#define EditorLogWarn(...)
		#define EditorLogError(...)
		#define EditorLogTrace(...)


	#endif

#endif

	class Logger {

	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetEditorLogger() { return editorLogger; }

	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> editorLogger;

	};

}