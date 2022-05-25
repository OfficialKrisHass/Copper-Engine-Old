#include "EngineLoop.h"

#include "Engine/Debug/Log.h"

namespace Copper {

	void EngineLoop::Init() {

		Logger::Initialize();
		Logger::Log("EngineLoop Initialization started!");

	}

	void EngineLoop::Run() {

		Logger::Log("EngineLoop entered the program Loop!");

	}

	void EngineLoop::Shutdown() {

		Logger::Log("EngineLoop is shutting down");

	}

}